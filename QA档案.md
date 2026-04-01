# QA档案：Git 推送被拒绝（non-fast-forward）

## 基本信息
- 记录日期：2026-04-01
- 仓库路径：S:\Computer Basic
- 相关分支：main
- 相关远程：origin（已统一默认remote名称）

## 问题描述（Q）
执行 `git push -u origin main` 时被拒绝，提示：
- `non-fast-forward`
- 本地分支落后于远端分支，需先整合远端变更。

## 现象与证据
- 远端最初存在重复 remote 名称（都指向同一地址），增加了操作混淆风险。
- 本地 `main` 与远端 `main` 各有独立提交。
- 检查结果显示两者无共同祖先（`NO_MERGE_BASE`），属于“无共同历史”场景。

## 根因分析（A）
1. 本地与远端分支历史独立初始化，导致无法 fast-forward。
2. 直接 push 会被 Git 保护机制拒绝。
3. remote 命名不统一（存在两个别名）加大了误操作概率。

## 处理过程（A）
1. 统一远程仓库配置
   - 删除重复 remote
   - 将剩余 remote 重命名为 `origin`
2. 执行允许无共同历史的拉取
   - `git pull origin main --allow-unrelated-histories`
3. 处理合并冲突
   - 冲突文件：`README.md`
   - 清理冲突标记并保留最终内容
4. 提交并推送
   - `git add README.md`
   - `git commit -m "merge: resolve README conflict after unrelated histories pull"`
   - `git push -u origin main`

## 最终结果（A）
- 推送成功，远端更新完成。
- 本地分支已建立跟踪关系：`main -> origin/main`
- 当前状态正常，可继续常规开发流程。

## 验证记录
- 最近关键提交：`d91a933`（合并冲突修复提交）
- `git status -sb` 显示：`main...origin/main`（无冲突未解决状态）

## 经验反馈与改进建议
1. 新仓库首次推送前先确认远端是否已有提交（如 README、LICENSE）。
2. 保持单一 remote 命名（推荐 `origin`）。
3. 若提示 `non-fast-forward`，先 pull 再 push，避免直接强推。
4. 仅在明确需要覆盖远端时使用 `--force-with-lease`。

## 标准操作模板（可复用）
```bash
# 1) 先同步远端
git pull origin main --allow-unrelated-histories

# 2) 解决冲突后提交
git add .
git commit -m "merge: resolve conflicts"

# 3) 再推送
git push -u origin main
```

## 本次结论
这是一次典型的“本地与远端无共同历史”导致的推送拒绝问题，采用“先合并历史、再解决冲突、最后推送”的方案已闭环解决。

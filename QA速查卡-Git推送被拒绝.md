# QA速查卡：Git push 被拒绝（non-fast-forward）

## 适用场景
当你看到以下报错时使用：
- `! [rejected] main -> main (non-fast-forward)`
- `Updates were rejected because the tip of your current branch is behind its remote counterpart`

## 30秒判断
1. 先看远程是否混乱（是否有多个同地址 remote）
2. 再看本地和远端是否分叉
3. 有分叉就先 pull，再处理冲突，再 push

## 标准处理流程（推荐）
```bash
# 0) 查看状态
git remote -v
git branch -vv
git status -sb

# 1) 同步远端
git fetch --all --prune

# 2) 拉取并允许无共同历史（首次对接常见）
git pull origin main --allow-unrelated-histories

# 3) 有冲突就手动解决后提交
git add .
git commit -m "merge: resolve conflicts"

# 4) 推送
git push -u origin main
```

## 冲突处理要点
- 打开冲突文件，删除冲突标记：
  - `<<<<<<<`
  - `=======`
  - `>>>>>>>`
- 保留你最终想要的内容后再 `git add`。

## 仅在必须覆盖远端时使用（高风险）
```bash
git push -u origin main --force-with-lease
```
说明：会改写远端历史，团队协作时谨慎使用。

## remote 整理模板（建议只保留 origin）
```bash
git remote -v
git remote remove <重复remote名>
git remote rename <当前remote名> origin
git remote -v
```

## 完成判据
```bash
git status -sb
```
看到 `main...origin/main` 且无冲突/未提交变更，即完成。

# Git 初学介绍

Git 是一个用于管理代码创作进度的工具。

## 仓库与分支

- 仓库（Repository）可以理解为一个项目的存档空间。
- 分支（Branch）是仓库中的独立开发线路。
- 仓库 == 项目 == 存档 

## 参考教程

- 官方教程《Pro Git》中可重点阅读：Getting Started - First-Time Git Setup。

## 0. 下载与验证

在本地可通过终端（CMD）输入以下命令，验证 Git 是否安装成功：

```bash
git --version
```

## 1. 配置 Git 用户名和邮箱

首次使用 Git 时，需要先配置本地用户名和邮箱。常用全局配置（global）：

```bash
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```

说明：

- 用户名：建议使用你常用的平台用户名。
- 邮箱：建议使用 GitHub 绑定邮箱，便于提交记录关联账号。

## 2. 本地上传到仓库的基本流程

### 2.1 创建仓库

创建仓库即初始化仓库（Initialize Repository）。

### 2.2 保存存档

每次提交时需要自己命名提交信息（commit message），用于说明本次修改内容。

Click--保存存档即提交（Commit）。

## 3.远程提交 Github

### 3.1 连接远程仓库 （仓库name：本地项目name）

github提交前需要加速，可使用工具 Watt Toolkit 或采用网络代理 浏览“ overflow ” 、网络全局代理
- 本地仓库：可在github项目的 “setting” 中重命名仓库name

推送项目：发布Branch（Publish Branch）

选择仓库性质：Public（公开）或Private（私密）

- **远程仓库：用于将本地项目提交至远程github仓库。**

在GitHub主页面（任意），右上角的 **+** 按钮，选择 **New Repository** ，设置仓库名称、描述、性质 ，之后再点击 **Create Repository** 创建仓库。

回到本地（vscode），打包好我们的本地项目，再“更改(SOURCE CONTROL)”一行，找到“更多操作”，选择“添加远程仓库（Add Remote Repository）” ，即可选择需要提交的仓库


## 4.项目信息

可在“图表(SOURCE CONTROL GRAPH)”中查看提交历史记录，了解项目进展情况。

- 云☁图标 表示远程项目（github）当前状态。

## 5.交互

在本地查看github项目的提交日志log
- 包括提交记录、提交人、提交时间等信息。
```bash
git log

```
注：需要在存档的目录下 运行此命令

## 6. 撤销（项目回滚）












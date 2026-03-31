Git

CORE:
# Git 工作区
- **工作目录(Working Directory)**工作区，平时存放项目代码的地方
- 暂存区(Staging Area) 用于临时存放你的改动，也叫索引(Index)，只是一个文件
- 资源库(Repository或Git Directory) 安全存放数据的位置，包含所有版本，HEAD指向最新的版本

*远程*
- **远程仓库(Remote Repository)**托管代码的服务器（多种）

## 关系图：
WD -`$git add file`-> SA -`$git commit`-> Repo -`$git push`-> Re Repo
WD <-`$git check`- SA <-`$git reset`- Repo <- `$git pull`- Re Repo

Commands:

```bash
$ git config -l    # 列出所有配置
$ git config --system --list    # 列出系统级配置
$ git config --global --list    # 列出全局(用户)配置

```
*阅读模式下，常用 q 退出*

本地文件配置：  git的配置，本质上就是文件
- Git\etc\gitconfig   # 系统级配置
- C:\Users\Administrator\.gitconfig   # 用户级配置
*用户配置可自行配置*
```bash
$ git config --global user.name "name111"
$ git config --global user.email "111@outlook.com"

#终端执行命令后，即会自动生成.gitconfig文件，内容如下：

[user]
	email = 111@outlook.com
	name = name111

```

[end...]
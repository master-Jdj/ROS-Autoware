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

## Env Commands:

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

# 项目创建和克隆

## 本地初始化仓库,使用git bash进入项目文件夹，执行以下命令：
```bash
$ git init
```
## 克隆远程仓库
```bash
$ git clone [url]
```

# git常用命令
```bash
$ git status	# 查看当前状态
$ git add .	# 添加所有文件 到暂存区
$ git commit -m "message代表本次提交的信息"	# 提交 到本地仓库
$ git push origin master	# 推送到远程仓库
$ git pull origin master	# 拉取远程仓库
```
# 忽略文件
设置忽略文件 .gitignore

" # " 表示注释
【可使用linux通配符】
" * " 忽略所有文件   示例： *.txt   忽略所有 .txt 文件
" ! " 排除文件       示例： ！lib.txt  但是 lib.txt 不被忽略
" / " 忽略所有子目录  示例： /temp  只忽略根目录下的 temp 文件夹
                    示例2： doc/  只忽略 doc 文件夹下的所有文件
" /* " 忽略子目录下文件   示例： doc/*.txt  只忽略 doc/.txt 文件，但不会忽略 doc/sever/.txt

# 分支管理  避免交集冲突；支持多个分支并行执行，代码不冲突，同时存在多个版本
1、假设存在冲突，解决办法修改重新提交。如：A分支和B分支都修改了同一行代码，提交后会提示冲突，解决办法：修改代码（确定保留A/B分支的代码）后重新提交即可。
2、一般存在其他分支dev分支，开发人员在dev分支上进行开发，完成后合并到master分支，master分支保持稳定。不允许直接修改master分支代码。
```bash
#新建分支
$ git branch branch_name
#切换分支
$ git checkout branch_name
#新建分支并切换
$ git checkout -b branch_name
#合并分支到当前分支
#当前main分支，命令指将origin(远程名)/dev(分支)分支合并到main分支
$ git merge branch_name 
#删除分支
$ git branch -d branch_name
#删除远程分支
$ git push origin --delete branch_name
$ git branch -dr [remote/branch]
#文件取消跟踪,先拉取最新的代码，取消跟踪后再推送
$ git rm --cached -- ["~/相对路径/file"]

```

[end...]
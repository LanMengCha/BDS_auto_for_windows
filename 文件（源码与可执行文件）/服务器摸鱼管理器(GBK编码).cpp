
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

    cout << "��ӭ��\n����LanMengCha�ķ������������㹤��\n";
    Sleep(100);
    cout << "��ʼƥ�䴰�ھ��\n";

    HWND window = FindPid(CheckModule("bedrock_server.exe"));
    //�������ھ����Ѱ�ң����õ����ҵķ���˵Ĵ���������ֲ��������������룡����
    cout << "����ƥ�䷵��ֵ��" << window;
    if (window == 0)
    {
        cout << "\nƥ��ʧ��\n";
    }
    else
    {
        cout << "\nƥ��ɹ�\n";
    }
    cout << "�������ⰴ����ʼ����������\n";
    cin.get();
    string m;
    m = "save hold";PrintInBDS(window,m);Sleep(1000);
    m = "save query";PrintInBDS(window,m);Sleep(1000);
    m = "save resume";PrintInBDS(window,m);Sleep(1000);
    cout << "\n����������....";
    Sleep(2000);
    cout << "\n�������\n";
    cout << "��ѡ��Ҫִ�еĲ���\n" << "��1��->����ģʽ\n��2��->����ģʽ\n��3��->����ģʽ\n";
    int link;
    do
    {
        cout << "<server>_��������:";
        cin >> link;
        if (link == 1)
        {
            /*��������д*/
        }
        else if (link == 2)
        {
            /*��������д*/
        }
        else if (link == 3)
        {
            /*��������д */
        }
        else
        {
            cout << "����������������ԡ�";
        }
        









    } while (window != 0);
    cout << "�������н������������ⰴ���˳�\n";
    cin.get();
    cout << "СQ�ÿɰ���������";
    return 0;
}



//������¥���õ��ĺ���


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

int PrintInBDS(HWND window,string command /*��������window�����ӽ������д���ָ��һ����*/)
{
    for (int i = 0; i < command.size(); i++)
    {
        char s;
        s = command[i];
        SendMessage(window,WM_CHAR,WPARAM(s),0);
        cout << "#";
    }
    SendMessage(window,WM_CHAR,WPARAM(),0);
    cout << "���ͳɹ�";
    return 0;
}



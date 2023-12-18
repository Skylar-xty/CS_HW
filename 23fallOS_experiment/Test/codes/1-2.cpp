// version???
#include <windows.h>
#include <iostream>

// ???????????????��??????????
int main()
{
    // ��ȡ��ǰ���̵�ID
    DWORD dwIdThis=:: GetCurrentProcessId();

    // ��ȡ��ǰ��������Ĳ���ϵͳ�汾��Ϣ
    DWORD dwVerReq=:: GetProcessVersion(dwIdThis);
    WORD wMajorReq=(WORD)(dwVerReq>16) ;   // ��Ҫ�汾��
    WORD wMinorReq=(WORD)(dwVerReq & 0xffff) ;
    std :: cout << "Process ID: "<< dwIdThis
                   <<", requires OS: " << wMajorReq  
                   << wMinorReq << std :: endl ;

    // �����ṹ�壬���ڻ�ȡ����ϵͳ����ϸ��Ϣ
    OSVERSIONINFOEX osvix;
    :: ZeroMemory(&osvix, sizeof(osvix) ) ;
    osvix.dwOSVersionInfoSize=sizeof(osvix) ;

    // ʹ�øú������osvix�ṹ�壬�Ի�ȡ��ǰ����ϵͳ�İ汾��Ϣ
    :: GetVersionEx(reinterpret_cast < LPOSVERSIONINFO > (&osvix)) ;
    std :: cout << "Running on OS:" << osvix.dwMajorVersion <<"."
                << osvix.dwMinorVersion << std :: endl;


    // ������ϵͳ�Ƿ�ʽWindows NTϵ��(2000+)������ǣ�������ǰ���̵����ȼ�����Ϊ��
    if (osvix.dwPlatformId==VER_PLATFORM_WIN32_NT && osvix.dwMajorVersion >= 5)
    {
        // ????????
        :: SetPriorityClass(
        :: GetCurrentProcess() ,			// ��ȡ��ǰ���̵ľ��
        HIGH_PRIORITY_CLASS);		    // ���ý��̵����ȼ�Ϊ��

        //
        std::cout << "Task Manager should  now indicate this "
                 "process is high priority."<< std :: endl;
    }
}

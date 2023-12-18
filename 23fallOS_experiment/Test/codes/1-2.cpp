// version???
#include <windows.h>
#include <iostream>

// ???????????????·??????????
int main()
{
    // 获取当前进程的ID
    DWORD dwIdThis=:: GetCurrentProcessId();

    // 获取当前进程所需的操作系统版本信息
    DWORD dwVerReq=:: GetProcessVersion(dwIdThis);
    WORD wMajorReq=(WORD)(dwVerReq>16) ;   // 主要版本号
    WORD wMinorReq=(WORD)(dwVerReq & 0xffff) ;
    std :: cout << "Process ID: "<< dwIdThis
                   <<", requires OS: " << wMajorReq  
                   << wMinorReq << std :: endl ;

    // 创建结构体，用于获取操作系统的详细信息
    OSVERSIONINFOEX osvix;
    :: ZeroMemory(&osvix, sizeof(osvix) ) ;
    osvix.dwOSVersionInfoSize=sizeof(osvix) ;

    // 使用该函数填充osvix结构体，以获取当前操作系统的版本信息
    :: GetVersionEx(reinterpret_cast < LPOSVERSIONINFO > (&osvix)) ;
    std :: cout << "Running on OS:" << osvix.dwMajorVersion <<"."
                << osvix.dwMinorVersion << std :: endl;


    // 检查操作系统是否式Windows NT系列(2000+)，如果是，它将当前进程的优先级设置为高
    if (osvix.dwPlatformId==VER_PLATFORM_WIN32_NT && osvix.dwMajorVersion >= 5)
    {
        // ????????
        :: SetPriorityClass(
        :: GetCurrentProcess() ,			// 获取当前进程的句柄
        HIGH_PRIORITY_CLASS);		    // 设置进程的优先级为高

        //
        std::cout << "Task Manager should  now indicate this "
                 "process is high priority."<< std :: endl;
    }
}

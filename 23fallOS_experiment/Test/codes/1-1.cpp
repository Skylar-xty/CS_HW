// proccreate项目
#include <windows.h>
#include <iostream>
#include <stdio.h>

// 创建传递过来的进程的克隆过程并赋于其ID值
void StartClone(int nCloneID)
{
    // 提取用于当前可执行文件的文件名
    TCHAR szFilename[MAX_PATH] ; //存储当前可执行文件的文件名
    //该函数用于获取当前进程的文件路径并将其存储在"szFilename"中
    :: GetModuleFileName(NULL, szFilename, MAX_PATH) ;

    // 格式化用于子进程的命令行并通知其EXE文件名和克隆ID
    TCHAR szCmdLine[MAX_PATH]; //存储命令行参数
    //将当前可执行文件的路径和'nCloneID'组合成一个命令行字符串
	:: sprintf(szCmdLine,"\"%s\" %d",szFilename,nCloneID);

	// 用于子进程的STARTUPINFO结构
    STARTUPINFO si; //指定新进程的一些属性
    // 将si初始化为0
    :: ZeroMemory(reinterpret_cast <void*> (&si) , sizeof(si) ) ;
    si.cb = sizeof(si) ;				// 必须是本结构的大小

    // 返回的用于子进程的进程信息
    PROCESS_INFORMATION pi;

    // 利用同样的可执行文件和命令行创建进程，并赋于其子进程的性质
    BOOL bCreateOK=::CreateProcess(                 //使用CreateProcess创建一个新的进程
        szFilename,					// 产生这个EXE的应用程序的名称
        szCmdLine,					// 告诉其行为像一个子进程的标志
        NULL,						// 缺省的进程安全性
        NULL,						// 缺省的线程安全性
        FALSE,						// 不继承句柄
        CREATE_NEW_CONSOLE,			// 使用新的控制台
        NULL,						// 新的环境
        NULL,						// 当前目录
        &si,						// 启动信息
        &pi) ;						// 返回的进程信息

    // 对子进程释放引用
    //如果创建进程成功，将关闭'pi.hProcess'和'pi.hThread'句柄，释放对新进程的引用
    if (bCreateOK)
    {
        :: CloseHandle(pi.hProcess) ;
        :: CloseHandle(pi.hThread) ;
    }
}

int main(int argc, char* argv[] )
{
    // 确定进程在列表中的位置
    int nClone(0) ;
    if (argc > 1)
    {
        // 从第二个参数中提取克隆ID
        :: sscanf(argv[1] , "%d" , &nClone) ;
    }

    // 显示进程位置
    std :: cout << "Process ID:" << :: GetCurrentProcessId()
                << ", Clone ID:" << nClone
                << std :: endl;

    // 检查是否有创建子进程的需要
    const int c_nCloneMax=5; //最大克隆数
    if (nClone < c_nCloneMax)
    {
        // 发送新进程的命令行和克隆号
        StartClone(++nClone) ;
    }
    std :: cout <<"wake up"<<std :: endl;
    // 在终止之前暂停一下 (l/2秒)
    :: Sleep(500) ;
    //std :: cout <<"wake up"<<std :: endl;
    return 0;
}

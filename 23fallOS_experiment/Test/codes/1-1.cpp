// proccreate��Ŀ
#include <windows.h>
#include <iostream>
#include <stdio.h>

// �������ݹ����Ľ��̵Ŀ�¡���̲�������IDֵ
void StartClone(int nCloneID)
{
    // ��ȡ���ڵ�ǰ��ִ���ļ����ļ���
    TCHAR szFilename[MAX_PATH] ; //�洢��ǰ��ִ���ļ����ļ���
    //�ú������ڻ�ȡ��ǰ���̵��ļ�·��������洢��"szFilename"��
    :: GetModuleFileName(NULL, szFilename, MAX_PATH) ;

    // ��ʽ�������ӽ��̵������в�֪ͨ��EXE�ļ����Ϳ�¡ID
    TCHAR szCmdLine[MAX_PATH]; //�洢�����в���
    //����ǰ��ִ���ļ���·����'nCloneID'��ϳ�һ���������ַ���
	:: sprintf(szCmdLine,"\"%s\" %d",szFilename,nCloneID);

	// �����ӽ��̵�STARTUPINFO�ṹ
    STARTUPINFO si; //ָ���½��̵�һЩ����
    // ��si��ʼ��Ϊ0
    :: ZeroMemory(reinterpret_cast <void*> (&si) , sizeof(si) ) ;
    si.cb = sizeof(si) ;				// �����Ǳ��ṹ�Ĵ�С

    // ���ص������ӽ��̵Ľ�����Ϣ
    PROCESS_INFORMATION pi;

    // ����ͬ���Ŀ�ִ���ļ��������д������̣����������ӽ��̵�����
    BOOL bCreateOK=::CreateProcess(                 //ʹ��CreateProcess����һ���µĽ���
        szFilename,					// �������EXE��Ӧ�ó��������
        szCmdLine,					// ��������Ϊ��һ���ӽ��̵ı�־
        NULL,						// ȱʡ�Ľ��̰�ȫ��
        NULL,						// ȱʡ���̰߳�ȫ��
        FALSE,						// ���̳о��
        CREATE_NEW_CONSOLE,			// ʹ���µĿ���̨
        NULL,						// �µĻ���
        NULL,						// ��ǰĿ¼
        &si,						// ������Ϣ
        &pi) ;						// ���صĽ�����Ϣ

    // ���ӽ����ͷ�����
    //����������̳ɹ������ر�'pi.hProcess'��'pi.hThread'������ͷŶ��½��̵�����
    if (bCreateOK)
    {
        :: CloseHandle(pi.hProcess) ;
        :: CloseHandle(pi.hThread) ;
    }
}

int main(int argc, char* argv[] )
{
    // ȷ���������б��е�λ��
    int nClone(0) ;
    if (argc > 1)
    {
        // �ӵڶ�����������ȡ��¡ID
        :: sscanf(argv[1] , "%d" , &nClone) ;
    }

    // ��ʾ����λ��
    std :: cout << "Process ID:" << :: GetCurrentProcessId()
                << ", Clone ID:" << nClone
                << std :: endl;

    // ����Ƿ��д����ӽ��̵���Ҫ
    const int c_nCloneMax=5; //����¡��
    if (nClone < c_nCloneMax)
    {
        // �����½��̵������кͿ�¡��
        StartClone(++nClone) ;
    }
    std :: cout <<"wake up"<<std :: endl;
    // ����ֹ֮ǰ��ͣһ�� (l/2��)
    :: Sleep(500) ;
    //std :: cout <<"wake up"<<std :: endl;
    return 0;
}

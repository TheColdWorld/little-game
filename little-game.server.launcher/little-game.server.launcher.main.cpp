#include "pch.h"
#include "functions.h"
data datas;
int port0, port1;
HWND consolehwnd;
WSADATA wsaData;
STARTUPINFO Server_1_start_INFO = { sizeof(Server_1_start_INFO) };
PROCESS_INFORMATION  Server_1_INFO;
bool Ctrlhandler(DWORD fdwctrltype)
{
    switch (fdwctrltype)
    {
        // handle the ctrl-c signal.
    case CTRL_C_EVENT:
        printf("关闭中...请稍后");
        TerminateProcess(Server_1_INFO.hProcess, 0);
        Sleep(200);
        return(true);
        // ctrl-close: confirm that the user wants to exit.
    case CTRL_CLOSE_EVENT:
        //控制台结束时 要做的事情
        printf("关闭中...请稍后");
        TerminateProcess(Server_1_INFO.hProcess, 0);
        Sleep(200);
        return(true);
        // pass other signals to the next handler.
    case CTRL_BREAK_EVENT:
        Sleep(200);
        return false;
    case CTRL_LOGOFF_EVENT:
        Sleep(200);
        return false;
    case CTRL_SHUTDOWN_EVENT:
        Sleep(200);
        return false;
    default:
        return false;
    }
}

void unicodefilein(const wchar_t* filename, const wchar_t* in)
{
    FILE* fp = NULL;
    if (_waccess_s(filename, 06) != 0)
    {
        _wfopen_s(&fp,filename, L"a+");
        char header[] = { 0xFF,0xfe };
        fwrite(header, 1, sizeof(header), fp);
    }
    else _wfopen_s(&fp,filename, L"a+");
    fwrite(in, 1, wcslen(in) * 2, fp);
    fflush(fp);
    fwrite(L"\r\n", 1, 2, fp);
    fclose(fp);
}
void unicodefilein(const wchar_t* filename,wchar_t* in)
{
    FILE* fp = NULL;
    if (_waccess_s(filename, 06) != 0)
    {
        _wfopen_s(&fp, filename, L"a+");
        char header[] = { 0xFF,0xfe };
        fwrite(header, 1, sizeof(header), fp);
    }
    else _wfopen_s(&fp, filename, L"a+");
    fwrite(in, 1, wcslen(in) * 2, fp);
    fflush(fp);
    fwrite(L"\r\n", 1, 2, fp);
    fclose(fp);
}
void unicodefilein(const wchar_t* filename, wchar_t* in1, wchar_t* in2)
{
    FILE* fp = NULL;
    if (_waccess_s(filename, 06) != 0)
    {
        _wfopen_s(&fp, filename, L"a+");
        char header[] = { 0xFF,0xfe };
        fwrite(header, 1, sizeof(header), fp);
    }
    else _wfopen_s(&fp, filename, L"a+");
    fwrite(in1, 1, wcslen(in1) * 2, fp);
    fwrite(in2, 1, wcslen(in2) * 2, fp);
    fflush(fp);
    fwrite(L"\r\n", 1, 2, fp);
    fclose(fp);
}
void unicodefilein(const wchar_t* filename,const wchar_t* in1,const wchar_t* in2)
{
    FILE* fp = NULL;
    if (_waccess_s(filename, 06) != 0)
    {
        _wfopen_s(&fp, filename, L"a+");
        char header[] = { 0xFF,0xfe };
        fwrite(header, 1, sizeof(header), fp);
    }
    else _wfopen_s(&fp, filename, L"a+");
    fwrite(in1, 1, wcslen(in1) * 2, fp);
    fwrite(in2, 1, wcslen(in2) * 2, fp);
    fflush(fp);
    fwrite(L"\r\n", 1, 2, fp);
    fclose(fp);
}
int wmain(int argc, wchar_t* argv[])
{
    datas.inappname(argv[0]);
    std::system("chcp 65001>nul");
    switch (WSAStartup(MAKEWORD(2, 2), &wsaData))
    {
    case 0:
        break;
    case WSASYSNOTREADY:
        MessageBox(NULL, L"err:基础网络子系统尚未准备好进行网络通信。\n请重启电脑试试,或者检查网络库", L"错误", MB_OK | MB_ICONERROR);
        printf("err:基础网络子系统尚未准备好进行网络通信。\n请重启电脑试试,或者检查网络库");
        pause;
        return -1;
        break;
    case WSAVERNOTSUPPORTED:
        MessageBox(NULL, L"err:此特定的Windows套接字实现未提供所请求的Windows套接字支持的版本。\n请更新网络库", L"错误", MB_OK | MB_ICONERROR);
        printf("err:此特定的Windows套接字实现未提供所请求的Windows套接字支持的版本。\n请更新网络库");
        pause;
        return -1;
        break;
    case WSAEINPROGRESS:
        MessageBox(NULL, L"err:Windows Sockets 1.1的阻止操作正在进行中。\n请重新启动", L"错误", MB_OK | MB_ICONERROR);
        printf("err:Windows Sockets 1.1的阻止操作正在进行中。\n请重新启动");
        pause;
        return -1;
        break;
    case WSAEPROCLIM:
        MessageBox(NULL, L"err:Windows套接字实现所支持的任务数已达到限制。\n请检查系统udp任务数或重新启动", L"错误", MB_OK | MB_ICONERROR);
        printf("err:Windows套接字实现所支持的任务数已达到限制。\n请检查系统udp任务数或重新启动");
        pause;
        return -1;
        break;
    case WSAEFAULT:
        MessageBox(NULL, L"内部错误", L"错误", MB_OK | MB_ICONERROR);
        printf("内部错误");
        pause;
        return -1;
        break;
    }
    switch (argc)
    {
    case 1:
        break;
    case 2:
    {
        wchar_t a[100];
        wcscpy(a, argv[1]);
        switch (a[0])
        {
        case L'-':
        {
            switch (a[1])
            {
            case L's':
            {
                wchar_t b[1024];
                datas.editport1(GetPrivateProfileInt(L"swap", L"port", 32766, L"swap.ini"));
                GetPrivateProfileStringW(L"swap", L"ipp1", NULL, b, 1024, L"swap.ini");
                datas.editipp1(b);
                memset(&b, 0, sizeof(b));
                GetPrivateProfileStringW(L"swap", L"ipp2", NULL, b, 1024, L"swap.ini");
                datas.editipp2(b);
                memset(&b, 0, sizeof(b));
                server_1(&datas);
            }
            case L'v':
            {
                printf("Little_Game_server\nVersion:0.1.0.0\n");
                    return 0;
            }
            default:
            {
                printf("参数错误\n");
                return -1;
                break;
            }
            }
            break;
        }
        default:
            return 0;
            break;
        }
    }
    case 3:
    {
        printf("参数冲突\n");
        return -1;
    }
    default:
    {
        printf("传参过多\n");
        return -1;
    }
    }
       
    

    if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)Ctrlhandler, true))
    {
        consolehwnd = GetConsoleWindow();
        if (_waccess_s(L"server.ini", 06) != 0)
        {
            unicodefilein(L"server.ini", L";这是服务端的配置文件,你可以在服务器关闭时修改服务器配置");
            unicodefilein(L"server.ini", L"[port settings]");
            unicodefilein(L"server.ini", L"port0=32765");
            unicodefilein(L"server.ini", L";此项为玩家分配服务端和游戏中确认连接的端口(客户端连接的端口)");
            unicodefilein(L"server.ini", L"port1=32766");
            unicodefilein(L"server.ini", L";此项为游戏本体与客户端交换数据的端口(计算在服务端)");
        }
        LPWSTR a = new TCHAR[255];
        port0 = GetPrivateProfileInt(L"port settings", L"port0", 32765, L"./server.ini");
        port1 = GetPrivateProfileInt(L"port settings", L"port1", 32766, L"./server.ini");
        if (port0 <= 1024)
        {
            UINT flag = MessageBox(consolehwnd, L"警告！\n设置中的端口0低于1024，此为系统保留端口，极有可能被占用，请问是否继续?", L"警告", MB_YESNO | MB_ICONWARNING);
            switch (flag)
            {
            case IDOK:
                break;
            case IDNO:
                return -1;
            }
        }
        if (port1 <= 1024)
        {
            UINT flag = MessageBox(consolehwnd, L"警告！\n设置中的端口1低于1024，此为系统保留端口，极有可能被占用，请问是否继续?", L"警告", MB_YESNO | MB_ICONWARNING);
            switch (flag)
            {
            case IDOK:
                break;
            case IDNO:
                return -1;
            }
        }
        datas.editport0(port0);
        datas.editport1(port1);
        server_0(&datas);
        return 0;
    }
}


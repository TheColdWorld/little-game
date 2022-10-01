#include "pch.h"
#include "functions.h"
data datas;
int port0, port1;
HWND consolehwnd;
WSADATA wsaData;
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
int wmain(int argc, wchar_t* argv[])
{
    datas.inappname(argv[0]);
    consolehwnd = GetConsoleWindow();
    std::system("chcp 65001>nul");
    if (argc ==2)
    {
        ATL::CString a = argv[1];
        if (a == "server_1")
        {
            port1 = GetPrivateProfileInt(L"swaper", L"port1", 32766, L"./swap.ini");
            datas.editport1(port1);
            if (port1 <= 1024)
            {
                UINT flag = MessageBox(consolehwnd, L"二次警告！\n设置中的端口1低于1024，此为系统保留端口，极有可能被占用，请问是否继续?", L"二次警告", MB_YESNO | MB_ICONWARNING);
                switch (flag)
                {
                case IDOK:
                    break;
                case IDNO:
                    return -1;
                }
            }
            free(&port1);
            LPWSTR a = new TCHAR[255];
            GetPrivateProfileString(L"swaper", L"ip1", NULL, a, 255, L"./swap.ini");
            if (a == NULL)
            {
                MessageBox(consolehwnd, L"内部错误", L"错误", MB_OK | MB_ICONERROR);
                printf("内部错误");
                pause;
                return -2;
            }
            else datas.editipp1(a);
            memset(&a, 0, sizeof(LPWSTR));
            GetPrivateProfileString(L"swaper", L"ip2", NULL, a, 255, L"./swap.ini");
            if (a == NULL)
            {
                MessageBox(consolehwnd, L"内部错误", L"错误", MB_OK | MB_ICONERROR);
                printf("内部错误");
                pause;
                return -2;
            }
            else datas.editipp2(a);
            free(&a);
        }
        else
        {
            printf("errer:传入参数错误");
        }
        return 0;
    }
    if (argc > 2)
    {
        printf("errer:传入参数过多");
        return -1;
    }
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
        UINT flag = MessageBox(consolehwnd,L"警告！\n设置中的端口0低于1024，此为系统保留端口，极有可能被占用，请问是否继续?", L"警告", MB_YESNO | MB_ICONWARNING);
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
    server_0(&datas);
    return 0;
}


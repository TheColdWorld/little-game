#include "pch.h"
#include "functions.h"
LPCWSTR to_LPCWSTR(PCSTR in)
{
    CString a = in;
    return a;
}
LPCWSTR to_LPCWSTR(std::string in)
{
    CString a = in.c_str();
    return a;
}
char* WcharToChar(const wchar_t* wc)
{
    char* m_char = NULL;
    delete m_char;
    m_char = NULL;
    int len = WideCharToMultiByte(CP_ACP, 0, wc, wcslen(wc), NULL, 0, NULL, NULL);
    m_char = new char[len + 1];
    WideCharToMultiByte(CP_ACP, 0, wc, wcslen(wc), m_char, len, NULL, NULL);
    m_char[len] = '\0';
    return m_char;
}
wchar_t* chartowchar(const char* cchar)
{
    wchar_t* m_wchar;
    int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
    m_wchar = new wchar_t[len + 1];
    MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), m_wchar, len);
    m_wchar[len] = '\0';
    return m_wchar;
}
wchar_t* chartowchar(char* cchar)
{
    wchar_t* m_wchar;
    int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
    m_wchar = new wchar_t[len + 1];
    MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), m_wchar, len);
    m_wchar[len] = '\0';
    return m_wchar;
}
int server_0(data* arg)
{
    bool openable=false;
    int pc = 0;
    double time1 = clock();
    SOCKET server_0;
    server_0 = socket(AF_INET, SOCK_DGRAM, 0);
    int len_0;
    SOCKADDR_IN addrClent;
    SOCKADDR_IN addrSrv;
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(arg->getport0());
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    bind(server_0, (LPSOCKADDR)&addrSrv, sizeof(SOCKADDR_IN));
    listen(server_0, 5);
    printf("分配服务端：启动成功，等待发送数据\n");
    endl;
    len_0 = sizeof(SOCKADDR);
    CHAR recv_buf[CHAR_MAX];
    char IP[1024];
    while (1)
    {
        // 接收数据
        if (SOCKET_ERROR != recvfrom(server_0, recv_buf, sizeof(recv_buf), 0, (SOCKADDR*)&addrClent, &len_0))
        {
            switch (atoi(recv_buf))
            {
            default:
                break;
            case 1: 
            {

                switch (pc)
                {
                case 0: {
                    memset(&recv_buf, 0, CHAR_MAX);
                    memset(&IP, 0, sizeof(IP));
                    inet_ntop(addrClent.sin_family, &addrClent.sin_addr,IP, 327);
                    arg->editipp1(chartowchar(IP));
                    sendto(server_0, "1", strlen("1"), 0, (SOCKADDR*)&addrClent, len_0);//给予玩家代号
                    pc++;
                    sendto(server_0, std::to_string(arg->getport1()).c_str(), strlen(std::to_string(arg->getport1()).c_str()), 0, (SOCKADDR*)&addrClent, len_0);
                    sendto(server_0, "3", strlen("3"), 0, (SOCKADDR*)&addrClent, len_0);
                    printf("分配服务端：玩家1加载完毕\n");
                    break;
                }
                case 1: {
                    memset(&recv_buf, 0, CHAR_MAX);
                    memset(&IP, 0, sizeof(IP));
                    inet_ntop(addrClent.sin_family, &addrClent.sin_addr, IP, 327);
                    arg->editipp2(chartowchar(IP));
                    sendto(server_0, "2", strlen("2"), 0, (SOCKADDR*)&addrClent, len_0);//给予玩家代号
                    pc++;
                    sendto(server_0, std::to_string(arg->getport1()).c_str(), strlen(std::to_string(arg->getport1()).c_str()), 0, (SOCKADDR*)&addrClent, len_0);
                    sendto(server_0, "3", strlen("3"), 0, (SOCKADDR*)&addrClent, len_0);
                    printf("分配服务端：玩家2加载完毕\n");
                    break;
                }
                default:
                    break;
                }
                if (pc == 2&&!openable)
                {
                    printf("分配服务端：开启游戏服务器...\n");
                    //printf("分配服务端：关闭分配服务器...\n");
                    //closesocket(server_0);
                    std::async(std::launch::async, CreateServer_1, arg);
                    openable = true;
                    //server_1(arg);
                }
                break;
            }
            case 2:
            {
                sendto(server_0, std::to_string(-2).c_str(), strlen(std::to_string(-2).c_str()), 0, (SOCKADDR*)&addrClent, len_0);
                break;
            }
            }
        }
    }
}

int server_1(data* arg)
{
    pause;
    SOCKET client_1;
    client_1 = socket(AF_INET, SOCK_DGRAM, 0);
    int len_1;
    SOCKADDR_IN server_1_addr;
    SOCKADDR_IN client_1_addr;
    memset(&server_1_addr, 0, sizeof(server_1_addr));
    server_1_addr.sin_family = AF_INET;
    server_1_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_1_addr.sin_port = htons(arg->getport1());
    int  pt1 = arg->getport1();//for debug
    bind(client_1, (SOCKADDR*)&server_1_addr, sizeof(SOCKADDR));
    printf("游戏服务端：服务端加载完毕\n");
    endl;
    len_1 = sizeof(SOCKADDR);
    while (true)
    {
        if (client_1 == SOCKET_ERROR)
        {
            printf("Socket Error：%d\n", WSAGetLastError());
            pause;
            return WSAGetLastError();
        }
        char recv_buf[CHAR_MAX];
        recvfrom(client_1, recv_buf, sizeof(recv_buf), 0, (SOCKADDR*)&client_1_addr, &len_1);
        if (to_LPCWSTR(inet_ntop(client_1_addr.sin_family, &client_1_addr.sin_addr, new char[327], 327)) == arg->getipp1() )
        {

        }
        else if (to_LPCWSTR(inet_ntop(client_1_addr.sin_family, &client_1_addr.sin_addr, new char[327], 327)) == arg->getipp2())
        {

        }
        else continue;
    }
}
void CreateServer_1(data* arg)
{
    wchar_t exec[MAX_PATH];
    wcscpy(exec, arg->getappname());
    wchar_t args[MAX_PATH];
    std::wstring wstr = arg->getappname();
    wstr += L" -s";
    wcscpy(args, wstr.c_str());
    SECURITY_ATTRIBUTES sa;
    sa.bInheritHandle = TRUE;
    sa.lpSecurityDescriptor = NULL;
    sa.nLength = sizeof(sa);
    system("del \"swap.ini\">nul 2>nul");
    unicodefilein(L"swap.ini", L"[swap]");
    unicodefilein(L"swap.ini", L"ipp1=",arg->getipp1().c_str());
    unicodefilein(L"swap.ini", L"ipp2=",arg->getipp2().c_str());
    unicodefilein(L"swap.ini", L"port=", std::to_wstring(arg->getport1()).c_str());
    if (!CreateProcessW(exec,args , &sa, NULL, TRUE,CREATE_NEW_CONSOLE, NULL, NULL, &Server_1_start_INFO, &Server_1_INFO)) printf("errer,%d\n", GetLastError());
  system("pause");
}

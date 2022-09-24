#include "pch.h"
#include "little-game.server.servers.h"
class data
{
public:
    void editport0(int Port0) { port0 = Port0; }
    void editport1(int Port1) { port1 = Port1; }
    void editport2(int Port2) { port2 = Port2; }
    int getport0() { return port0; }
    int getport1() { return port1; }
    int getport2() { return port2; }
    int getportp1() { return portplayer1; }
    int getportp2() { return portplayer2; }
    std::string getipp1() { return IPplayer1; }
    std::string getipp2() { return IPplayer2; }
    void editipp1(std::string IP) { IPplayer1 = IP; }
    void editipp2(std::string IP) { IPplayer2 = IP; }
    void editpop1(int port) { portplayer1 = port; }
    void editpop2(int port) { portplayer2 = port; }
private:
    int port0;
    int port1;
    int port2;
    int portplayer1;
    int portplayer2;
    std::string IPplayer1;
    std::string IPplayer2;
};
int ccc = 0;
int loadwsa()
{
    WSADATA wsaData;
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
        MessageBox(NULL, L"err:Windows套接字实现所支持的任务数已达到限制。\n请检查系统udp任务数或重新启动", L"错误",MB_OK | MB_ICONERROR);
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
    return 0;
}
void sender(SOCKET socket ,char* buf)
{
    char buffer[1024] = "\0";
    strcpy_s(buffer, buf);
    int nSize = strlen(buffer);
    WCHAR bufU[1024] = L"\0";
    int bufUSize = MultiByteToWideChar(CP_ACP, 0, buffer, -1, bufU, 1024);
    size_t tempsize = wcslen(bufU);
    send(socket, (char*)bufU, bufUSize * 2, 0);
}
int server_0(data* arg)
{
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
    PCSTR  IP;
    while (1)
    {
        // 接收数据
        if (SOCKET_ERROR != recvfrom(server_0, recv_buf, sizeof(recv_buf), 0, (SOCKADDR*)&addrClent, &len_0))
        {
            if (atoi(recv_buf) == 1) 
            {
                switch (pc)
                {
                case 0:
                {
                    memset(&recv_buf, 0, CHAR_MAX);
                    memset(&IP, 0, sizeof(IP));
                    IP = inet_ntop(addrClent.sin_family, &addrClent.sin_addr, new char[327], 327);
                    arg->editipp2(IP);
                    arg->editpop2(ntohs(addrClent.sin_port));
                    sendto(server_0, "1", strlen("1"), 0, (SOCKADDR*)&addrClent, len_0);//给予玩家代号
                    pc++;
                    sendto(server_0, std::to_string(arg->getport1()).c_str(), strlen(std::to_string(arg->getport1()).c_str()), 0, (SOCKADDR*)&addrClent, len_0);
                    sendto(server_0, "3", strlen("3"), 0, (SOCKADDR*)&addrClent, len_0);
                    printf("分配服务端：玩家1加载完毕\n");
                    break;
                }
                case 1:
                {
                    memset(&recv_buf, 0, CHAR_MAX);
                    memset(&IP, 0, sizeof(IP));
                    IP = inet_ntop(addrClent.sin_family, &addrClent.sin_addr, new char[327], 327);
                    arg->editipp2(IP);
                    arg->editpop2(ntohs(addrClent.sin_port));
                    sendto(server_0, "2", strlen("2"), 0, (SOCKADDR*)&addrClent, len_0);//给予玩家代号
                    pc++;
                    sendto(server_0, std::to_string(arg->getport2()).c_str(), strlen(std::to_string(arg->getport2()).c_str()), 0, (SOCKADDR*)&addrClent, len_0);
                    sendto(server_0, "3", strlen("3"), 0, (SOCKADDR*)&addrClent, len_0);
                    printf("分配服务端：玩家2加载完毕\n");
                    break;
                }
                default:
                    break;
                }
                if (pc == 2)
                {
                    printf("分配服务端：开启游戏服务器...\n");
                    printf("分配服务端：关闭分配服务器...\n");
                    closesocket(server_0);
                    std::async(std::launch::async, server_1, arg);
                }
            }
        }
    }
}
int server_1(data* arg)
{
    SOCKET client_1;
    client_1 = socket(AF_INET, SOCK_DGRAM, 0);
    int len_1;
    SOCKADDR_IN server_1_addr;
    SOCKADDR_IN client_1_addr;
    memset(&server_1_addr, 0, sizeof(server_1_addr));
    server_1_addr.sin_family = AF_INET;
    server_1_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_1_addr.sin_port = htons(arg->getport1());
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
        if (inet_ntop(client_1_addr.sin_family, &client_1_addr.sin_addr, new char[327], 327) == arg->getipp1() && ntohs(client_1_addr.sin_port) != arg->getportp1())
        {

        }
        else if (inet_ntop(client_1_addr.sin_family, &client_1_addr.sin_addr, new char[327], 327) == arg->getipp2() && ntohs(client_1_addr.sin_port) != arg->getportp2())
        {

        }
        else continue;
    }
}

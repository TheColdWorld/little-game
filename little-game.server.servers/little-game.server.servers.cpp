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
void loadwsa()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
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
void server_0(data* arg)
{
    int playercount = 0;
    double time1 = clock();
    SOCKET server_0;
    server_0 = socket(AF_INET, SOCK_STREAM, 0);
    int len_0;
    SOCKADDR_IN server_0_addr;
    SOCKADDR_IN client_0_addr;
    memset(&server_0_addr, 0, sizeof(server_0_addr));
    server_0_addr.sin_family = AF_INET;
    server_0_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_0_addr.sin_port = htons(arg->getport0());
    bind(server_0, (SOCKADDR*)&server_0_addr, sizeof(SOCKADDR));
    listen(server_0, 5);
    printf("分配服务端：启动成功，等待链接\n");
    endl;
    len_0 = sizeof(SOCKADDR);
    setsockopt(server_0, SOL_SOCKET, SO_SNDBUF, (char*)&ccc, sizeof(ccc));
    while (true)
    {
        SOCKET client_0 = accept(server_0, (SOCKADDR*)&client_0_addr, &len_0);
        if (client_0 == SOCKET_ERROR)
        {
            printf("error：%d\n", WSAGetLastError());
            pause;
            return;
        }
        else printf("分配服务端：有新的链接创建成功\n");
        endl;
        CHAR recv_buf[CHAR_MAX];
        recvfrom(client_0, recv_buf, 5, 0, (SOCKADDR*)&client_0_addr, &len_0);
        PCSTR  IP;
        if (atoi(recv_buf)==1)
        {
            switch (playercount)
            {
            case 0:
            {
                sender(client_0, const_cast<char*>("1"));//给予玩家代号
                memset(&recv_buf, 0, CHAR_MAX);
                printf("分配服务端：玩家1成功进入游戏\n");
                endl;
                playercount++;
                sender(client_0, const_cast<char*>(std::to_string( arg->getport1()).c_str()));
                arg->editpop1(ntohs(client_0_addr.sin_port));
                IP = inet_ntop(client_0_addr.sin_family, &client_0_addr.sin_addr, new char[327], 327);
                arg->editipp1(IP);
                sender(client_0, const_cast<char*>("3"));
                std::future<void> s = std::async(std::launch::async, server_1, arg);
                closesocket(client_0);
                break;
            }
            case 1:
            {
                sender(client_0, const_cast<char*>("2"));//给予玩家代号

                memset(&recv_buf, 0, CHAR_MAX);
                printf("分配服务端：玩家2成功进入游戏\n");
                endl;
                playercount++;
                sender(client_0, const_cast<char*>(std::to_string(arg->getport1()).c_str()));
                memset(&IP, 0, sizeof(IP));
                IP = inet_ntop(client_0_addr.sin_family, &client_0_addr.sin_addr, new char[327], 327);
                arg->editipp2(IP);
                arg->editpop2(ntohs(client_0_addr.sin_port));
                sender(client_0, const_cast<char*>("3"));
                std::future<void> s1 = std::async(std::launch::async, server_2, arg);
                closesocket(client_0);
                break;
            }
            case 2:
                sender(client_0, const_cast<char*>("-1"));//返回人满请求
                memset(&recv_buf, 0, CHAR_MAX);
                printf("分配服务端：玩家数量已满，拒绝链接\n");
                closesocket(client_0);
                endl;
                break;
            default:
                closesocket(client_0);
                break;
            }
        }
        else sender(server_0, const_cast<char*>("-2"));; closesocket(client_0);
            
    }
}
void server_1(data* arg)
{
    SOCKET server_1;
    server_1 = socket(AF_INET, SOCK_STREAM, 0);
    int len_1;
    SOCKADDR_IN server_1_addr;
    SOCKADDR_IN client_1_addr;
    memset(&server_1_addr, 0, sizeof(server_1_addr));
    server_1_addr.sin_family = AF_INET;
    server_1_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_1_addr.sin_port = htons(arg->getport1());
    bind(server_1, (SOCKADDR*)&server_1_addr, sizeof(SOCKADDR));
    listen(server_1, 5);
    printf("游戏服务端：玩家1加载完毕\n");
    endl;
    len_1 = sizeof(SOCKADDR);
    setsockopt(server_1, SOL_SOCKET, SO_SNDBUF, (char*)&ccc, sizeof(ccc));
    while (true)
    {
        SOCKET client_1 = accept(server_1, (SOCKADDR*)&client_1_addr, &len_1);
        if (client_1 == SOCKET_ERROR)
        {
            printf("error：%d\n", WSAGetLastError());
            pause;
            return;
        }
        char recv_buf[CHAR_MAX];
        recvfrom(client_1, recv_buf, sizeof(recv_buf), 0, (SOCKADDR*)&client_1_addr, &len_1);
        if (inet_ntop(client_1_addr.sin_family, &client_1_addr.sin_addr, new char[327], 327) != arg->getipp1())
        {
            printf("游戏服务端：发现陌生链接，已自动断开\n");
            endl; closesocket(client_1);
            continue;
        }
        if (ntohs(client_1_addr.sin_port) != arg->getportp1())
        {
            printf("游戏服务端：发现陌生链接，已自动断开\n");
            endl;
            closesocket(client_1);
            continue;
        }
        else switch (atoi(recv_buf))
        {
        default:
            break;
        }
    }
}
void server_2(data* arg)
{
    SOCKET server_2;
    server_2 = socket(AF_INET, SOCK_STREAM, 0);
    int len_2;
    SOCKADDR_IN server_2_addr;
    SOCKADDR_IN client_2_addr;
    memset(&server_2_addr, 0, sizeof(server_2_addr));
    server_2_addr.sin_family = AF_INET;
    server_2_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_2_addr.sin_port = htons(arg->getport2());
    bind(server_2, (SOCKADDR*)&server_2_addr, sizeof(SOCKADDR));
    listen(server_2, 5);
    printf("游戏服务端：玩家2加载完毕\n");
    endl;
    len_2 = sizeof(SOCKADDR);
    setsockopt(server_2, SOL_SOCKET, SO_SNDBUF, (char*)&ccc, sizeof(ccc));
    while (true)
    {
        SOCKET client_2 = accept(server_2, (SOCKADDR*)&client_2_addr, &len_2);
        if (client_2 == SOCKET_ERROR)
        {
            printf("error：%d\n", WSAGetLastError());
            pause;
            return;
        }
        char recv_buf[CHAR_MAX];
        recvfrom(client_2, recv_buf, sizeof(recv_buf), 0, (SOCKADDR*)&client_2_addr, &len_2);
        if (inet_ntop(client_2_addr.sin_family, &client_2_addr.sin_addr, new char[327], 327) != arg->getipp2())
        {
            printf("游戏服务端：发现陌生链接，已自动断开\n");
            endl;
            closesocket(client_2);
            continue;
        }
        if (ntohs(client_2_addr.sin_port) != arg->getportp2())
        {
            printf("游戏服务端：发现陌生链接，已自动断开\n");
            endl;
            closesocket(client_2);
            continue;
        }
        else switch (atoi(recv_buf))
        {
        default:
            break;
        }
    }
}

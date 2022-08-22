// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern"C" __declspec(dllexport) void server_0(int port0,int port1,int port2,int portplayer1,int portplayer2 ,std::string IPplayer1,std::string IPplayer2,bool debug)
{
    double time1 = clock();
    int playercount =0;
    SOCKET server_0;
    server_0 = socket(AF_INET, SOCK_STREAM, 0);
    int len_0;
    SOCKADDR_IN server_0_addr;
    SOCKADDR_IN client_0_addr;
    memset(&server_0_addr, 0, sizeof(server_0_addr));
    server_0_addr.sin_family = AF_INET;
    server_0_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_0_addr.sin_port = htons(port0);
    bind(server_0, (SOCKADDR*)&server_0_addr, sizeof(SOCKADDR));
    listen(server_0, 5);
    printf("分配服务端：启动成功，等待链接");
    endl;
    len_0 = sizeof(SOCKADDR);
    while (true)
    {
        SOCKET client_0 = accept(server_0, (SOCKADDR*)&client_0_addr, &len_0);
        if (client_0 == SOCKET_ERROR)
        {
            printf("error：%d\n", WSAGetLastError());
            pause;
            return;
        }
        else printf("分配服务端：有新的链接创建成功");
        endl;
        char recv_buf[CHAR_MAX];
        recvfrom(client_0, recv_buf, sizeof(recv_buf), 0, (SOCKADDR*)&client_0_addr, &len_0);
        PCSTR  IP;
        switch (atoi(recv_buf))
        {
        case 1:
            switch (playercount)
            {
            case 0:
            {
                send(client_0, "1", sizeof("1"), 0);//给予玩家代号
                memset(&recv_buf, 0, CHAR_MAX);
                printf("分配服务端：玩家1成功进入游戏");
                endl;
                playercount++;
                send(client_0, std::to_string(port1).c_str(), sizeof(std::to_string(port1).c_str()), 0);
                memset(recv_buf, 0, CHAR_MAX);
                portplayer1 = ntohs(client_0_addr.sin_port);
                IP = inet_ntop(client_0_addr.sin_family, &client_0_addr.sin_addr, new char[327], 327);
                IPplayer1 = IP;
                send(client_0, "0", sizeof("0"), 0);
                break;
            }
            case 1:
            {
                send(client_0, "2", sizeof("2"), 0);//给予玩家代号
                memset(&recv_buf, 0, CHAR_MAX);
                printf("分配服务端：玩家2成功进入游戏");
                endl;
                playercount++;
                send(client_0, std::to_string(port2).c_str(), sizeof(std::to_string(port2).c_str()), 0);
                memset(recv_buf, 0, CHAR_MAX);
                memset(&IP, 0, sizeof(IP));
                IP = inet_ntop(client_0_addr.sin_family, &client_0_addr.sin_addr, new char[327], 327);
                IPplayer2 = IP;
                portplayer2 = ntohs(client_0_addr.sin_port);
                send(client_0, "0", sizeof("0"), 0);
                break;
            }
            case 2:
                send(client_0, "-1", sizeof("-1"), 0);//返回人满请求
                memset(&recv_buf, 0, CHAR_MAX);
                printf("分配服务端：玩家数量已满，拒绝链接");
                endl;
                break;
            default:
                break;
            }
            break;
        case 2:
            if (debug)
            {
                send(client_0, "0", sizeof("0"), 0);
                int costs = int(clock() - time1) / CLOCKS_PER_SEC;
                int costm = 0;
                int costh = 0;
                for (; costs >= 60; costm++) costs -= 60;
                for (; costm >= 60; costh++) costm -= 60;
                std::string tm = std::to_string(costh) + ":" + std::to_string(costm) + ":" + std::to_string(costs);
                send(client_0, tm.c_str(), sizeof(tm.c_str()), 0);//运行时间
                HANDLE handle = GetCurrentProcess();
                PROCESS_MEMORY_COUNTERS pmc;
                GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
                double  memory = pmc.WorkingSetSize / static_cast<double>(1024) / static_cast <double>(1024) / static_cast <double>(10);
                send(client_0, std::to_string(memory).c_str(), sizeof(std::to_string(memory).c_str()), 0);//内存占用
                send(client_0, std::to_string(playercount).c_str(), sizeof(std::to_string(playercount).c_str()), 0);//玩家数量
            }
            else  send(client_0, "-1", sizeof("-1"), 0);
            break;
        default:
            break;
        }
        closesocket(client_0);
    }
}
extern"C" __declspec(dllexport) void server_1(int port1,std::string IPplayer1,int portplayer1)
{
    SOCKET server_1;
    server_1 = socket(AF_INET, SOCK_STREAM, 0);
    int len_1;
    SOCKADDR_IN server_1_addr;
    SOCKADDR_IN client_1_addr;
    memset(&server_1_addr, 0, sizeof(server_1_addr));
    server_1_addr.sin_family = AF_INET;
    server_1_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_1_addr.sin_port = htons(port1);
    bind(server_1, (SOCKADDR*)&server_1_addr, sizeof(SOCKADDR));
    listen(server_1, 5);
    printf("游戏服务端：玩家1加载完毕");
    endl;
    len_1 = sizeof(SOCKADDR);
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
        if (inet_ntop(client_1_addr.sin_family, &client_1_addr.sin_addr, new char[327], 327) != IPplayer1)
        {
            printf("游戏服务端：发现陌生链接，已自动断开");
            endl; closesocket(client_1);
            continue;
        }
        if (ntohs(client_1_addr.sin_port) != portplayer1)
        {
            printf("游戏服务端：发现陌生链接，已自动断开");
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
extern"C" __declspec(dllexport) void server_2(int port2,int portplayer2,std::string IPplayer2)
{

    SOCKET server_2;
    server_2 = socket(AF_INET, SOCK_STREAM, 0);
    int len_2;
    SOCKADDR_IN server_2_addr;
    SOCKADDR_IN client_2_addr;
    memset(&server_2_addr, 0, sizeof(server_2_addr));
    server_2_addr.sin_family = AF_INET;
    server_2_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_2_addr.sin_port = htons(port2);
    bind(server_2, (SOCKADDR*)&server_2_addr, sizeof(SOCKADDR));
    listen(server_2, 5);
    printf("游戏服务端：玩家2加载完毕");
    endl;
    len_2 = sizeof(SOCKADDR);
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
        if (inet_ntop(client_2_addr.sin_family, &client_2_addr.sin_addr, new char[327], 327) != IPplayer2)
        {
            printf("游戏服务端：发现陌生链接，已自动断开");
            endl;
            closesocket(client_2);
            continue;
        }
        if (ntohs(client_2_addr.sin_port) != portplayer2)
        {
            printf("游戏服务端：发现陌生链接，已自动断开");
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
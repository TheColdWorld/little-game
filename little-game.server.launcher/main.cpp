#include "pch.h"
#pragma comment(lib,"little-game.server.servers.lib")
#include "..\little-game.server.servers\little-game.server.servers.h"
LPCWSTR to_LPCWSTR(const char* in)
{
    CString a = in;
    LPCWSTR b = a;
    return b;
}
std::string LPWSTR_to_string(LPWSTR in)
{
    CString a = in;
    std::string b(CW2A(a.GetString()));
    return b;
}
int main()
{
    if (_access("./config.ini", 00) == -1)
    {
        FILE* f;
        fopen_s(&f, "./config.ini", "w+");
        fprintf(f, ";这是服务端的配置文件,你可以在服务器关闭时修改服务器配置\n");
        fprintf(f, "[port settings]\nport0=32765");
        fprintf(f, "\n;此项为玩家分配服务端的端口(向全体开放的端口)\n");
        fprintf(f, "port1=32766");
        fprintf(f, "\n;此项为对玩家1开放的端口（自动分配）\n");
        fprintf(f, "port2=32767");
        fprintf(f, "\n;此项为对玩家2开放的端口（自动分配）\n");
        fclose(f);
    }
    LPWSTR a= new TCHAR[255];
    port0 = GetPrivateProfileInt(to_LPCWSTR("port settings"), to_LPCWSTR("port0"), 32765, to_LPCWSTR("./config.ini"));
    port1 = GetPrivateProfileInt(to_LPCWSTR("port settings"), to_LPCWSTR("port1"), 32766, to_LPCWSTR("./config.ini"));
    port2 = GetPrivateProfileInt(to_LPCWSTR("port settings"), to_LPCWSTR("port2"), 32767, to_LPCWSTR("./config.ini"));
    printf("主线程:设置加载完毕！\n");
    datas.editport0(port0);
    datas.editport1(port1);
    datas.editport2(port2);
    switch (loadwsa())
    {
    case 0:
        break;
    case -1:
        return -1;
        break;
    }
    server_0(&datas);
}
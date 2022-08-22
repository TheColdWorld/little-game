#include "pch.h"
#pragma comment(lib,"little-game.server.servers.lib")
#include "little-game.server.servers.h"

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
        fprintf(f, "[Global settings]\ndebug=true");
        fprintf(f, "\n;是否开启调试模式(默认为true)\n");
        fclose(f);
    }
    LPWSTR a= new TCHAR[255];
    GetPrivateProfileString(to_LPCWSTR("Global settings"), to_LPCWSTR("debug"), NULL, a, 255, to_LPCWSTR("./config.ini"));
    if(a ==NULL) { printf("[config.ini]中[Global settings]中[debug]值未找到，请检查[config.ini],解决后重新启动程序");}
    if (LPWSTR_to_string(a) == "true" || LPWSTR_to_string(a) == "TRUE") { debug = true; }
    else if (LPWSTR_to_string(a) == "false" || LPWSTR_to_string(a) == "false") { debug = false; }
    else { printf("[config.ini]中[Global settings]中[debug]值非法,它应该是布尔值，而不是[%s]", LPWSTR_to_string(a).c_str()); }
    port0 = GetPrivateProfileInt(to_LPCWSTR("port settings"), to_LPCWSTR("port0"), 32765, to_LPCWSTR("./config.ini"));
    port1 = GetPrivateProfileInt(to_LPCWSTR("port settings"), to_LPCWSTR("port1"), 32766, to_LPCWSTR("./config.ini"));
    port2 = GetPrivateProfileInt(to_LPCWSTR("port settings"), to_LPCWSTR("port2"), 32767, to_LPCWSTR("./config.ini"));
    printf("主线程:设置加载完毕！");
    datas.editport0(port0);
    datas.editdebug(debug);
    datas.editport1(port1);
    datas.editport2(port2);
    std::future<void> val = std::async(std::launch::async, server_0, &datas);
}
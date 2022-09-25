#pragma once
#undef _MBCS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#define  _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <assert.h>
#include <vector>
#include <iostream>
#include <tchar.h>
#include <io.h>
#include <cstdio>
#include <cwchar>
#include <thread>
#include <future>
#include <fstream>
#include <string>
#include <atlstr.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#include <time.h>
#define cls std::system("cls")
#define pause std::system("pause>nul")
#define endl wprintf(L"\n")
class data
{
public:
    void editport0(int Port0) { port0 = Port0; }
    void editport1(int Port1) { port1 = Port1; }
    int getport0() { return port0; }
    int getport1() { return port1; }
    int getportp1() { return portplayer1; }
    int getportp2() { return portplayer2; }
    LPCWSTR getipp1() { return IPplayer1; }
    LPCWSTR getipp2() { return IPplayer2; }
    void editipp1(LPCWSTR IP) { IPplayer1 = IP; }
    void editipp2(LPCWSTR IP) { IPplayer2 = IP; }
private:
    int port0;
    int port1;
    int portplayer1;
    int portplayer2;
    LPCWSTR IPplayer1;
    LPCWSTR IPplayer2;
};

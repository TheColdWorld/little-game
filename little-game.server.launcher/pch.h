#pragma once
#include <windows.h>
#include <io.h>
#include <fstream>
#include <stdio.h>
#include <atlstr.h>
#include <Thread>
#include <string>
#include "little-game.server.servers.h"
bool debug;
int port0;
int port1;
int port2;
int portplayer1;
int portplayer2;
std::string IPplayer1;
std::string IPplayer2;
#include <future>
class data
{
public:
    void editport0(int Port0) { port0 = Port0; }
    void editport1(int Port1) { port1 = Port1; }
    void editport2(int Port2) { port2 = Port2; }
    void editdebug(bool Debug) { debug = Debug; }
    int getport0() { return port0; }
    int getport1() { return port1; }
    int getport2() { return port2; }
    bool getdebug() { return debug; }
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
    bool debug;
    int portplayer1;
    int portplayer2;
    std::string IPplayer1;
    std::string IPplayer2;
};
data datas;
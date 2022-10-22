#include "pch.h"
#pragma once
int server_1(data* arg);
LPCWSTR to_LPCWSTR(PCSTR in);
void unicodefilein(const wchar_t* filename, const wchar_t* in);
void unicodefilein(const wchar_t* filename, wchar_t* in);
int server_0(data* arg);
LPCWSTR to_LPCWSTR(std::string in);
LPCWSTR to_LPCWSTR(PCSTR in);
char* WcharToChar(const wchar_t* wc);
wchar_t* chartowchar(const char* cchar);
wchar_t* chartowchar(char* cchar);
void CreateServer_1(data* arg);
void unicodefilein(const wchar_t* filename, wchar_t* in1, wchar_t* in2);
void unicodefilein(const wchar_t* filename, const wchar_t* in1, const wchar_t* in2);

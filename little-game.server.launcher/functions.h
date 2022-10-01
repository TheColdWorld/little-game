#include "pch.h"
#pragma once
int server_1(data* arg);
LPCWSTR to_LPCWSTR(PCSTR in);
void unicodefilein(const wchar_t* filename, const wchar_t* in);
int server_0(data* arg);
LPCWSTR to_LPCWSTR(std::string in);
LPCWSTR to_LPCWSTR(PCSTR in);
std::string GetStringByWchar(const WCHAR* wszString);

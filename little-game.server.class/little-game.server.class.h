#pragma once
#ifdef little_game_server_class_EXPORTS
#define little_game_server_class_API __declspec(dllexport)
#else
#define little_game_server_class_API __declspec(dllimport)
#endif
extern"C" little_game_server_class_API class player;
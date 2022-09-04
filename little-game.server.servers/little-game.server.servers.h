#pragma once
#ifdef LITTLE_GAME_SERVER_SERVERS_EXPORTS
#define LITTLE-GAME_SERVER_SERVERS_API __declspec(dllexport)
#else
#define LITTLE_GAME_SERVER_SERVERS_API __declspec(dllimport)
#endif // LITTLE-GAME.SERVER.SERVERS_EXPORTS
extern"C" LITTLE_GAME_SERVER_SERVERS_API class data;
extern"C" LITTLE_GAME_SERVER_SERVERS_API int loadwsa();
extern"C" LITTLE_GAME_SERVER_SERVERS_API void server_0(data * arg);
extern"C" LITTLE_GAME_SERVER_SERVERS_API void server_1(data * arg); 
extern"C" LITTLE_GAME_SERVER_SERVERS_API void server_2(data * arg);
#include "include.h"

#include <iostream>
#include <sstream>
#include <fstream>

void luaX_run(lua_State *L, const char *name, const char *function, int args)
{
	lua_getglobal(L, name);
	lua_getfield(L, -1, function);
	lua_pcall(L, args, LUA_MULTRET, 0);
}

void luaX_load(lua_State *L, const char *name, const char *filename)
{
	std::ifstream t(filename);

	std::stringstream script;
	script << name << " = {}; setmetatable(" << name << ", global_metatable); do local _ENV = " << name << "; ";
	script << t.rdbuf();
	script << " end;";

	luaL_loadstring(L, script.str().c_str());
	lua_pcall(L, 0, 0, 0);
}

void luaX_open(lua_State *L)
{
	luaL_loadstring(L, "global_metatable = {__index = _G};");
	lua_pcall(L, 0, 0, 0);
}

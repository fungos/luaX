#include "include.h"
#include "luax.h"

static int func_trace(lua_State *L)
{
	lua_isstring(L, 2);
	const char *msg = lua_tostring(L, 2);

	lua_isstring(L, 1);
	const char *name = lua_tostring(L, 1);
	fprintf(stdout, "[%s] %s\n", name, msg);

	return 0;
}

int main()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	luaX_open(L);

	lua_pushcclosure(L, func_trace, 0);
	lua_setglobal(L, "trace");

	luaX_load(L, "script1" ,"script1.lua");
	luaX_load(L, "script2", "script2.lua");

	luaX_run(L, "script1", "update", 0);
	luaX_run(L, "script2", "update", 0);

	lua_close(L);

	return 0;
}


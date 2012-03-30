#ifndef LUAX_H
#define LUAX_H

void luaX_fail(lua_State *L, const char *msg);
void luaX_run(lua_State *L, const char *name, const char *function, int args);
void luaX_load(lua_State *L, const char *name, const char *filename);
void luaX_open(lua_State *L);

#endif // LUAX_H

//gcc -I/usr/include/lua5.3 -L/usr/lib/x86_64-linux-gnu -llua5.3 main.cpp -o embed_lua

#include "lua.hpp"

int main() {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "main.lua");
    lua_close(L);
    return 0;
}

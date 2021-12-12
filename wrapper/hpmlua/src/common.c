#include "common.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void commonNewLibrary(lua_State *L, const luaL_Reg *functions) {
#if LUA_VERSION_NUM >= 502
	lua_createtable(L, 0, 0);
	luaL_setfuncs(L, functions, 0);
#else
	lua_createtable(L, 0, 0);
	luaL_register(L, NULL, functions);
#endif
}

void commonPushEnum(lua_State *L, int value, const CommonEnum *evalue) {
	int i;

	lua_createtable(L, 0, 0);

	for (i = 0; evalue[i].name != NULL; ++i) {
		/*
		 * Put as a map like table[i] = i so it's cleaner and
		 * more convenient for the user. The user is also able to reuse
		 * the table.
		 */
		if (value & evalue[i].value) {
			lua_pushinteger(L, evalue[i].value);
			lua_rawseti(L, -2, evalue[i].value);
		}
	}
}

void commonBindObject(lua_State *L, const CommonObject *def) {
	luaL_newmetatable(L, def->name);

	if (def->metamethods != NULL) {
#if LUA_VERSION_NUM >= 502
		luaL_setfuncs(L, def->metamethods, 0);
#else
		luaL_register(L, NULL, def->metamethods);
#endif
	}

	if (def->methods != NULL) {
		lua_createtable(L, 0, 0);
#if LUA_VERSION_NUM >= 502
		luaL_setfuncs(L, def->methods, 0);
#else
		luaL_register(L, NULL, def->methods);
#endif
		lua_setfield(L, -2, "__index");
	}

	lua_pop(L, 1);
}

void commonBindEnum(lua_State *L, int tindex, const char *tname, const CommonEnum *values) {
	int i;

	lua_createtable(L, 0, 0);

	for (i = 0; values[i].name != NULL; ++i) {
		lua_pushinteger(L, values[i].value);
		lua_setfield(L, -2, values[i].name);
	}

	if (tindex < 0)
		tindex--;

	lua_setfield(L, tindex, tname);
}

void commonBindLibrary(lua_State *L, const luaL_Reg *functions) {
#if LUA_VERSION_NUM >= 502
	luaL_setfuncs(L, functions, 0);
#else
	luaL_register(L, NULL, functions);
#endif
}

void *commonGetUserdata(lua_State *L, int index, const char *tname) { return luaL_checkudata(L, index, tname); }

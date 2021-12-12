
#define LUA_LIB
#include "common.h"

#include <hpm.h>
#include <lua5.3/lauxlib.h>
#include <lua5.3/lua.h>
#include <lua5.3/lualib.h>

#include "hpm_lmath.h"
#include "matrix.h"
#include "quat.h"
#include "vector.h"

static void push_int(lua_State *L, int val) { lua_pushnumber(L, val); }

static void push_uint(lua_State *L, unsigned int val) { lua_pushnumber(L, val); }

static void push_float(lua_State *L, float val) { lua_pushnumber(L, val); }

int commonGetEnum(lua_State *L, int tindex) {
	int value = 0;

	if (lua_type(L, tindex) == LUA_TNUMBER) {
		value = (int)lua_tonumber(L, tindex);
	} else if (lua_type(L, tindex) == LUA_TTABLE) {
		if (tindex < 0)
			tindex--;

		lua_pushnil(L);
		while (lua_next(L, tindex) != 0) {
			if (lua_type(L, -1) == LUA_TNUMBER)
				value |= lua_tointeger(L, -1);

			lua_pop(L, 1);
		}
	}

	return value;
}

static int l_init(lua_State *L) {
	if (lua_gettop(L) >= 1 && lua_type(L, 1) == LUA_TNUMBER) {
		int flag = commonGetEnum(L, 1);
		int result = hpm_init(flag);
		if (result != 0) {
		}
		lua_pushinteger(L, result);
		return 1;
	}
	lua_pushboolean(L, 0);
	return 1;
}

static int l_release(lua_State *L) {
	lua_pushinteger(L, hpm_release());
	return 1;
}

static int l_version(lua_State *L) {
	lua_pushstring(L, hpm_version());
	return 1;
}

static int l_hpm_support_cpu_feat(lua_State *L) {
	int v = hpm_support_cpu_feat(luaL_checkinteger(L, 1));
	lua_pushboolean(L, v);
	return 1;
}

static const luaL_Reg functions[] = {{"init", l_init},
									 {"release", l_release},
									 {"version", l_version},
									 {"hpm_support_cpu_feat", l_hpm_support_cpu_feat},
									 {NULL, NULL}};

/*
 * SDL.logCategory
 */
const CommonEnum LoggingCategory[] = {{"NOSIMD", HPM_NONE}, {"SSE", HPM_SSE},		  {"SSE2", HPM_SSE2},
									  {"SSE3", HPM_SSE3},	{"SSE41", HPM_SSE4_1},	  {"SSE42", HPM_SSE4_2},
									  {"AVX", HPM_AVX},		{"AVX2", HPM_AVX2},		  {"AVX512", HPM_AVX512},
									  {"NEON", HPM_NEON},	{"DEFAULT", HPM_DEFAULT}, {NULL, -1}};

static const struct {
	const luaL_Reg *functions;
} libraries[] = {{MatrixFunctions}, {VectorFunctions}, {QuatFunctions}, {MathFunctions}, {NULL}};

static const struct {
	const char *name;
	const CommonEnum *values;
} enums[] = {{"SIMD", LoggingCategory},
			 /* Logging */
			 {NULL, NULL}};

static const struct { const CommonObject *object; } objects[] = {{&Vector4}, {&Matrix4x4}, {&Quaternion}, {NULL}};

LUALIB_API int luaopen_lhpm(lua_State *L) {
	int i;
	//	lua_settop(L, 0);

	/* General functions */
	commonNewLibrary(L, functions);

	/* Library categories */
	for (i = 0; libraries[i].functions != NULL; ++i)
		commonBindLibrary(L, libraries[i].functions);

	/* Enumerations */
	for (i = 0; enums[i].values != NULL; ++i)
		commonBindEnum(L, -1, enums[i].name, enums[i].values);

	/* Object oriented data */
	for (i = 0; objects[i].object != NULL; ++i)
		commonBindObject(L, objects[i].object);

	return 1;
}

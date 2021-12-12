#include "hpm_lmath.h"
#include <hpm.h>

static int l_hpm_vec4_minfv(lua_State *L) {
	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpmvec4f c;
	hpm_vec4_minfv(a, b, &c);
	lua_pushlightuserdata(L, &c);
	return 1;
}

const luaL_Reg MathFunctions[] = {{"min", l_hpm_vec4_minfv}, {NULL, NULL}};

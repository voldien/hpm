#include "matrix.h"

static hpmvec4x4f_t *l_hpm_mat4x4_new(lua_State *L) {
	hpmvec4x4f_t *ptr = lua_newuserdata(L, sizeof(hpmvec4f));
	luaL_setmetatable(L, Matrix4x4.name);

	return ptr;
}

static int l_mat4x4(lua_State *L) {
	int top = lua_gettop(L);

	/*	Make sure it is only 16 at max.	*/
	if (top > 16) {
	}

	//	double x = luaL_checknumber(L, 1);
	hpmvec4x4f_t *ptr = l_hpm_mat4x4_new(L);

	for (int i = 0; i < top; i++) {
		(ptr[0])[i][i % 4] = luaL_checknumber(L, i + 1);
	}
	return 1;
}

static int l_mat4x4_x(lua_State *L) {
	lua_pushnumber(L, 0);
	return 1;
}

static int l_mat4x4_newindex(lua_State *L) {
	/*	(t,k,v)	*/
	hpmvec4x4f_t *a = commonGetAs(L, 1, Matrix4x4.name, hpmvec4x4f_t *);

	/*	Extract key and value.	*/
	int key = lua_tointeger(L, 2);
	float value = lua_tonumber(L, 3);

	// lua_
	// lua_
	// lua_pushnumber(L, 0);
	return 0;
}

static int l_mat4x4_index(lua_State *L) {

	/*	(t,k)	*/
	hpmvec4x4f_t *a = commonGetAs(L, 1, Matrix4x4.name, hpmvec4x4f_t *);
	int key = lua_tointeger(L, 2);
	assert(key >= 0 && key <= 3);

	return 1;
}

static int l_mat4x4_eq(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Matrix4x4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Matrix4x4.name, hpmvec4f *);
	lua_pushboolean(L, hpm_mat4x4_eqfv(a, b));
	return 1;
}

static int l_mat4x4_string(lua_State *L) {
	hpmvec4f *a = lua_touserdata(L, 1);
	char buf[64];
	int len = hpm_mat4x4_sprint(buf, a);
	lua_pushlstring(L, buf, len);
	return 1;
}

static int l_mat4x4_unm(lua_State *L) {

	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Matrix4x4.name, hpmvec4f *);
	l_hpm_mat4x4_new(L);
	hpmvec4f *b = commonGetAs(L, 2, Matrix4x4.name, hpmvec4f *);

	hpm_mat4x4_copyfv(b, a);
	hpm_mat4x4_addition_scalef(b, -1.0f);
	return 1;
}

static int l_mat4x4_add(lua_State *L) {

	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Matrix4x4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Matrix4x4.name, hpmvec4f *);
	l_hpmvec4(L);
	hpmvec4f *c = commonGetAs(L, 3, Matrix4x4.name, hpmvec4f *);

	hpm_mat4x4_copyfv(c, a);
	hpm_mat4x4_addition_scalefv(c, b);

	return 1;
}

static int l_mat4x4_sub(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Matrix4x4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Matrix4x4.name, hpmvec4f *);
	l_hpmvec4(L);
	hpmvec4f *c = commonGetAs(L, 3, Matrix4x4.name, hpmvec4f *);

	hpm_mat4x4_copyfv(b, c);
	hpm_mat4x4_addition_scalefv(c, a);

	return 1;
}

static int l_mat4x4_mul(lua_State *L) {

	int isnum1 = lua_isnumber(L, 1);
	int isnum2 = lua_isnumber(L, 2);

	if (isnum1 || isnum2) {
		float num;
		hpmvec4f *a;
		if (isnum2) {
			a = lua_touserdata(L, 1);
			num = lua_tonumber(L, 2);
		} else if (isnum1) {
			a = lua_touserdata(L, 2);
			num = lua_tonumber(L, 1);
		}
		l_hpm_mat4x4_new(L);
		hpm_mat4x4_addition_scalef(a, num);
	} else {
		hpmvec4f *a = lua_touserdata(L, 1);
		hpmvec4f *b = lua_touserdata(L, 2);
		l_hpm_mat4x4_new(L);
		hpm_mat4x4_addition_scalefv(a, b);
	}
	return 1;
}

static int l_mat4x4_div(lua_State *L) {

	int isnum1 = lua_isnumber(L, 1);
	int isnum2 = lua_isnumber(L, 2);

	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpm_mat4x4_addition_scalefv(a, b);
	return 0;
}
static int l_mat4x4_idiv(lua_State *L) {
	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpm_mat4x4_addition_scalefv(a, b);
	return 0;
}
static int l_mat4x4_mod(lua_State *L) {
	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpm_mat4x4_addition_scalefv(a, b);
	return 0;
}

static int l_mat4x4_pow(lua_State *L) {

	int isnum1 = lua_isnumber(L, 1);
	int isnum2 = lua_isnumber(L, 2);

	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpm_mat4x4_addition_scalefv(a, b);
	return 0;
}

static int l_mat4x4_determine(lua_State *L) {}

static int l_mat4x4_inverse(lua_State *L) {}

static int l_mat4x4_transpose(lua_State *L) {}

static int l_mat4x4_name(lua_State *L) {}

static int l_mat4x4_translate(lua_State *L) {}

static int l_mat4x4_rotate(lua_State *L) {}

static int l_mat4x4_scale(lua_State *L) {}

static int l_mat4x4_lookat(lua_State *L) {}

static int l_mat4x4_perspective(lua_State *L) {}

static int l_mat4x4_orth(lua_State *L) {}

static int l_mat4x4_unProject(lua_State *L) {}

static int l_mat4x4_identity(lua_State *L) {}

static const luaL_Reg UdpMethods[] = {{"r0", l_mat4x4_x},
									  {"r1", l_mat4x4_x},
									  {"r2", l_mat4x4_x},
									  {"r3", l_mat4x4_x},
									  {"determine", l_mat4x4_determine},
									  {"inverse", l_mat4x4_inverse},
									  {"transpose", l_mat4x4_transpose},
									  {NULL, NULL}};

static const luaL_Reg UdpMetamethods[] = {{"__name", l_mat4x4_name},		 {"__index", l_mat4x4_index},
										  {"__newindex", l_mat4x4_newindex}, {"__eq", l_mat4x4_newindex},
										  {"__tostring", l_mat4x4_newindex}, {"__unm", l_mat4x4_newindex},
										  {"__add", l_mat4x4_newindex},		 {"__sub", l_mat4x4_newindex},
										  {"__mul", l_mat4x4_newindex},		 {"__div", l_mat4x4_newindex},
										  {"__idiv", l_mat4x4_newindex},	 {"__mod", l_mat4x4_newindex},
										  {"__pow", l_mat4x4_newindex},		 {NULL, NULL}};

const CommonObject Matrix4x4 = {"matrix4x4", UdpMethods, UdpMetamethods};

const luaL_Reg MatrixFunctions[] = {{"mat4", l_mat4x4},
									{"translate", l_mat4x4_translate},
									{"rotate", l_mat4x4_rotate},
									{"scale", l_mat4x4_scale},
									{"lookat", l_mat4x4_lookat},
									{"perspective", l_mat4x4_perspective},
									{"orth", l_mat4x4_orth},
									{"unproj", l_mat4x4_unProject},
									{"identity", l_mat4x4_identity},
									{NULL, NULL}};

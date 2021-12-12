#include "quat.h"

static hpmquatf *l_hpm_quat_new(lua_State *L) {
	hpmquatf *ptr = lua_newuserdata(L, sizeof(hpmquatf));
	luaL_setmetatable(L, Quaternion.name);

	return ptr;
}

static int l_hpmquat(lua_State *L) {
	int top = lua_gettop(L);
	//	double x = luaL_checknumber(L, 1);
	hpmquatf *ptr = l_hpm_quat_new(L);
	for (int i = 0; i < top; i++) {
		(ptr[0])[i] = luaL_checknumber(L, i + 1);
	}
	return 1;
}

static int vec4_new(lua_State *L) {
	hpmquatf *ptr = lua_newuserdata(L, sizeof(hpmquatf));
	luaL_setmetatable(L, Quaternion.name);
	return 1;
}

static int l_quat_length(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_quat_square(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_quat_normalize(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_quat_dot(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_quat_conjugate(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}
static int l_quat_inverse(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_quat_pitch(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_quat_yaw(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_quat_roll(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);

	int type = lua_type(L, 1);
	float length = hpm_quat_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_quat_x(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	lua_pushnumber(L, hpm_quat_getwf(*a));
	return 1;
}

static int l_quat_y(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	lua_pushnumber(L, hpm_quat_getwf(*a));
	return 1;
}

static int l_quat_z(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	lua_pushnumber(L, hpm_quat_getwf(*a));
	return 1;
}

static int l_quat_w(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	lua_pushnumber(L, hpm_quat_getwf(*a));
	return 1;
}

static int l_quat_newindex(lua_State *L) {

	/*	(t,k,v)	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	int key = lua_tointeger(L, 2);
	float value = lua_tonumber(L, 3);

	(a[0])[key] = value;

	return 0;
}
static int l_quat_index(lua_State *L) {

	/*	(t,k)	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	int key = lua_tointeger(L, 2);

	lua_pushnumber(L, (*a)[key]);
	return 1;
}

static int l_quat_eq(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	hpmquatf *b = commonGetAs(L, 2, Quaternion.name, hpmquatf *);
	lua_pushboolean(L, hpm_vec4_eqfv(a, b));
	return 1;
}

static int l_quat_string(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	char buf[64];
	int len = hpm_quat_sprint(buf, a);
	lua_pushlstring(L, buf, len);
	return 1;
}

static int l_quat_unm(lua_State *L) {
	/*	*/
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	l_hpm_vec4_new(L);
	hpmquatf *b = commonGetAs(L, 2, Quaternion.name, hpmquatf *);

	hpm_vec4_copyfv(b, a);
	hpm_vec4_addition_scalef(b, -1.0f);
	return 1;
}

static int l_quat_add(lua_State *L) {

	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	hpmquatf *b = commonGetAs(L, 2, Quaternion.name, hpmquatf *);
	l_hpm_quat_new(L);
	hpmquatf *c = commonGetAs(L, 3, Quaternion.name, hpmquatf *);
	hpm_quat_copyfv(c, a);
	hpm_quat_addition_scalefv(c, b);
	return 1;
}

static int l_quat_sub(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	hpmquatf *b = commonGetAs(L, 2, Quaternion.name, hpmquatf *);
	l_hpm_quat_new(L);
	hpmquatf *c = commonGetAs(L, 3, Quaternion.name, hpmquatf *);

	hpm_quat_copyfv(c, a);
	hpm_quat_addition_scalefv(c, b);

	return 1;
}

static int l_quat_mul(lua_State *L) {

	int isnum1 = lua_isnumber(L, 1);
	int isnum2 = lua_isnumber(L, 2);

	l_hpm_quat_new(L);
	hpmquatf *c = commonGetAs(L, 3, Quaternion.name, hpmquatf *);

	if (isnum1 || isnum2) {
		float num;
		hpmquatf *a;
		if (isnum2) {
			a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
			num = lua_tonumber(L, 2);
		} else if (isnum1) {
			a = commonGetAs(L, 2, Quaternion.name, hpmquatf *);
			num = lua_tonumber(L, 1);
		}
		hpm_quat_copyfv(c, a);
		hpm_quat_multi_scalef(c, num);
	} else {
		// TODO check if vector or quaternion.
		hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
		hpmvec4f *b = commonGetAs(L, 2, Quaternion.name, hpmvec4f *);
		hpm_quat_multi_quatfv(a, b, c);

		hpm_quat_multi_quatfv(a, b, c);
	}
	return 1;
}

static int l_quat_div(lua_State *L) {

	int isnum1 = lua_isnumber(L, 1);
	int isnum2 = lua_isnumber(L, 2);

	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	hpmquatf *b = commonGetAs(L, 2, Quaternion.name, hpmquatf *);
	// hpm_quat_addition_scalefv(a, b);
	return 0;
}
static int l_quat_idiv(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	hpmquatf *b = commonGetAs(L, 2, Quaternion.name, hpmquatf *);
	// hpm_quat_addition_scalefv(a, b);
	return 0;
}
static int l_quat_mod(lua_State *L) {
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	hpmquatf *b = commonGetAs(L, 2, Quaternion.name, hpmquatf *);
	// hpm_quat_addition_scalefv(a, b);
	return 0;
}

static int l_quat_pow(lua_State *L) {
	int isnum1 = lua_isnumber(L, 1);
	int isnum2 = lua_isnumber(L, 2);
	//	hpm_quat_powfv()
	hpmquatf *a = commonGetAs(L, 1, Quaternion.name, hpmquatf *);
	hpmquatf *b = commonGetAs(L, 2, Quaternion.name, hpmquatf *);
	// hpm_quat_addition_scalefv(a, b);
	return 0;
}

static int l_quat_name(lua_State *L) {
	lua_pushstring(L, "quat");
	return 1;
}

static int l_quat_lerp(lua_State *L) {
	lua_pushstring(L, "quat");
	return 1;
}

static int l_quat_slerp(lua_State *L) {
	lua_pushstring(L, "quat");
	return 1;
}

static int l_quat_identity(lua_State *L) {
	lua_pushstring(L, "quat");
	return 1;
}

const luaL_Reg QuatFunctions[] = {
	{"quat", l_hpmquat}, {"lerp", l_quat_lerp}, {"slerp", l_quat_slerp}, {"identity", l_quat_identity}, {NULL, NULL}};

static const luaL_Reg QuatMethods[] = {{"x", l_quat_x},
									   {"y", l_quat_y},
									   {"z", l_quat_z},
									   {"w", l_quat_w},
									   {"length", l_quat_length},
									   {"square", l_quat_square},
									   {"normalize", l_quat_normalize},
									   {"dot", l_quat_dot},
									   {"conjugate", l_quat_conjugate},
									   {"inverse", l_quat_inverse},
									   {"pitch", l_quat_pitch},
									   {"yaw", l_quat_yaw},
									   {"roll", l_quat_roll},
									   {NULL, NULL}};

static const luaL_Reg QuatMetamethods[] = {{"__name", l_quat_name},			{"__index", l_quat_index},
										   {"__newindex", l_quat_newindex}, {"__eq", l_quat_eq},
										   {"__tostring", l_quat_string},	{"__unm", l_quat_unm},
										   {"__add", l_quat_add},			{"__sub", l_quat_sub},
										   {"__mul", l_quat_mul},			{"__div", l_quat_div},
										   {"__idiv", l_quat_idiv},			{"__mod", l_quat_mod},
										   {"__pow", l_quat_pow},			{NULL, NULL}};

const CommonObject Quaternion = {"quat", QuatMethods, QuatMetamethods};

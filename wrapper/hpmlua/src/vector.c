#include "vector.h"

static hpmvec4f *l_hpm_vec4_new(lua_State *L) {
	hpmvec4f *ptr = lua_newuserdata(L, sizeof(hpmvec4f));

	luaL_setmetatable(L, Vector4.name);

	return ptr;
}

static void l_hpm_vec4_new_ptr(lua_State *L, hpmvec4f *v) {
	// lua_newuserdata
	luaL_setmetatable(L, Vector4.name);
}

static int l_hpmvec4(lua_State *L) {
	int top = lua_gettop(L);

	/*	Make sure it is only four at max.	*/
	if (top > 4) {
	}
	//	double x = luaL_checknumber(L, 1);
	hpmvec4f *ptr = l_hpm_vec4_new(L);
	for (int i = 0; i < top; i++) {
		(ptr[0])[i] = luaL_checknumber(L, i + 1);
	}
	return 1;
}

static int vec4_new(lua_State *L) {
	hpmvec4f *ptr = lua_newuserdata(L, sizeof(hpmvec4f));
	luaL_setmetatable(L, Vector4.name);
	return 1;
}

static int l_vec4_length(lua_State *L) {
	/*	*/
	hpmvec4f *a = lua_topointer(L, 1);
	assert(a != NULL);

	int type = lua_type(L, 1);
	float length = hpm_vec4_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_vec4_square(lua_State *L) {
	/*	*/
	hpmvec4f *a = lua_topointer(L, 1);
	assert(a != NULL);

	int type = lua_type(L, 1);
	float length = hpm_vec4_lengthfv(a);
	lua_pushnumber(L, length);
	return 1;
}

static int l_vec4_normalize(lua_State *L) {
	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	l_hpm_vec4_new(L);
	hpmvec4f *b = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpm_vec4_copyfv(b, a);
	hpm_vec4_normalizefv(b);
	return 1;
}

static int l_vec4_min_component(lua_State *L) {
	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	l_hpm_vec4_new(L);
	hpmvec4f *b = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpm_vec4_copyfv(b, a);
	hpm_vec4_normalizefv(b);
	return 1;
}

static int l_vec4_max_component(lua_State *L) {
	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	l_hpm_vec4_new(L);
	hpmvec4f *b = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpm_vec4_copyfv(b, a);
	hpm_vec4_normalizefv(b);
	return 1;
}

static int l_vec4_min_abs_component(lua_State *L) {
	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	l_hpm_vec4_new(L);
	hpmvec4f *b = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpm_vec4_copyfv(b, a);
	hpm_vec4_normalizefv(b);
	return 1;
}

static int l_vec4_max_abs_component(lua_State *L) {
	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	l_hpm_vec4_new(L);
	hpmvec4f *b = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpm_vec4_copyfv(b, a);
	hpm_vec4_normalizefv(b);
	return 1;
}

static int l_vec4_x(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	lua_pushnumber(L, hpm_vec4_getxf(*a));
	return 1;
}

static int l_vec4_y(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	lua_pushnumber(L, hpm_vec4_getyf(*a));
	return 1;
}

static int l_vec4_z(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	lua_pushnumber(L, hpm_vec4_getzf(*a));
	return 1;
}

static int l_vec4_w(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	lua_pushnumber(L, hpm_vec4_getwf(*a));
	return 1;
}

static int l_vec4_newindex(lua_State *L) {
	/*	(t,k,v)	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	/*	Extract key and value.	*/
	int key = lua_tointeger(L, 2);
	float value = lua_tonumber(L, 3);

	/*	*/
	(a[0])[key] = value;

	return 0;
}
static int l_vec4_index(lua_State *L) {
	/*	(t,k)	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	int key = lua_tointeger(L, 2);
	assert(key >= 0 && key <= 3);
	/*	Assign value.	*/
	lua_pushnumber(L, (a[0])[key]);
	return 1;
}

static int l_vec4_eq(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);
	lua_pushboolean(L, hpm_vec4_eqfv(a, b));
	return 1;
}

static int l_vec4_string(lua_State *L) {
	hpmvec4f *a = lua_touserdata(L, 1);
	char buf[64];
	int len = hpm_vec4_sprint(buf, a);
	lua_pushlstring(L, buf, len);
	return 1;
}

static int l_vec4_unm(lua_State *L) {

	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	l_hpm_vec4_new(L);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);

	hpm_vec4_copyfv(b, a);
	hpm_vec4_addition_scalef(b, -1.0f);
	return 1;
}

static int l_vec4_add(lua_State *L) {

	/*	*/
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);
	l_hpmvec4(L);
	hpmvec4f *c = commonGetAs(L, 3, Vector4.name, hpmvec4f *);

	hpm_vec4_copyfv(c, a);
	hpm_vec4_addition_scalefv(c, b);

	return 1;
}

static int l_vec4_sub(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);
	l_hpmvec4(L);
	hpmvec4f *c = commonGetAs(L, 3, Vector4.name, hpmvec4f *);

	hpm_vec4_copyfv(b, c);
	hpm_vec4_addition_scalefv(c, a);

	return 1;
}

static int l_vec4_mul(lua_State *L) {

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
		l_hpm_vec4_new(L);
		hpm_vec4_addition_scalef(a, num);
	} else {
		hpmvec4f *a = lua_touserdata(L, 1);
		hpmvec4f *b = lua_touserdata(L, 2);
		l_hpm_vec4_new(L);
		hpm_vec4_addition_scalefv(a, b);
	}
	return 1;
}

static int l_vec4_div(lua_State *L) {

	int isnum1 = lua_isnumber(L, 1);
	int isnum2 = lua_isnumber(L, 2);

	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpm_vec4_addition_scalefv(a, b);
	return 0;
}
static int l_vec4_idiv(lua_State *L) {
	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpm_vec4_addition_scalefv(a, b);
	return 0;
}
static int l_vec4_mod(lua_State *L) {
	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpm_vec4_addition_scalefv(a, b);
	return 0;
}

static int l_vec4_pow(lua_State *L) {

	int isnum1 = lua_isnumber(L, 1);
	int isnum2 = lua_isnumber(L, 2);

	hpmvec4f *a = lua_touserdata(L, 1);
	hpmvec4f *b = lua_touserdata(L, 2);
	hpm_vec4_addition_scalefv(a, b);
	return 0;
}

static int l_vec4_name(lua_State *L) {
	lua_pushstring(L, "vec4");
	return 1;
}

static int l_vec4_lerp(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);
	float t = lua_tonumber(L, 3);
	l_hpmvec4(L);
	hpmvec4f *c = commonGetAs(L, 4, Vector4.name, hpmvec4f *);

	hpm_vec4_lerpfv(a, b, t, c);
	return 1;
}
static int l_vec4_slerp(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);
	float t = lua_tonumber(L, 3);
	l_hpmvec4(L);
	hpmvec4f *c = commonGetAs(L, 4, Vector4.name, hpmvec4f *);

	hpm_vec4_slerpfv(a, b, t, c);
	return 1;
}
static int l_vec4_dot2(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);

	lua_pushnumber(L, hpm_vec4_dotfv(a, b));
	return 1;
}
static int l_vec4_max(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);
	l_hpmvec4(L);
	hpmvec4f *c = commonGetAs(L, 3, Vector4.name, hpmvec4f *);

	hpm_vec4_maxfv(a, b, c);
	return 1;
}
static int l_vec4_min(lua_State *L) {
	hpmvec4f *a = commonGetAs(L, 1, Vector4.name, hpmvec4f *);
	hpmvec4f *b = commonGetAs(L, 2, Vector4.name, hpmvec4f *);
	l_hpmvec4(L);
	hpmvec4f *c = commonGetAs(L, 3, Vector4.name, hpmvec4f *);

	hpm_vec4_minfv(a, b, c);
	return 1;
}

const luaL_Reg VectorFunctions[] = {{"vec4", l_hpmvec4},  {"lerp", l_vec4_lerp}, {"slerp", l_vec4_slerp},
									{"dot", l_vec4_dot2}, {"max", l_vec4_max},	 {"min", l_vec4_min},
									{"one", l_vec4_min},  {"zero", l_vec4_min},	 {NULL, NULL}};

static const luaL_Reg UdpMethods[] = {{"x", l_vec4_x},
									  {"y", l_vec4_y},
									  {"z", l_vec4_z},
									  {"w", l_vec4_w},
									  {"length", l_vec4_length},
									  {"square", l_vec4_square},
									  {"normalize", l_vec4_normalize},
									  //									  {"makeUnitVector", l_vec4_length},
									  //{"dot", l_vec4_dot},
									  {"minComponent", l_vec4_min_component},
									  {"maxComponent", l_vec4_max_component},
									  {"maxAbsComponent", l_vec4_max_abs_component},
									  {"minAbsComponent", l_vec4_min_abs_component},
									  {NULL, NULL}};

static const luaL_Reg UdpMetamethods[] = {{"__name", l_vec4_name},		   {"__index", l_vec4_index},
										  {"__newindex", l_vec4_newindex}, {"__eq", l_vec4_eq},
										  {"__tostring", l_vec4_string},   {"__unm", l_vec4_unm},
										  {"__add", l_vec4_add},		   {"__sub", l_vec4_sub},
										  {"__mul", l_vec4_mul},		   {"__div", l_vec4_div},
										  {"__idiv", l_vec4_idiv},		   {"__mod", l_vec4_mod},
										  {"__pow", l_vec4_pow},		   {NULL, NULL}};

const CommonObject Vector4 = {"vec4", UdpMethods, UdpMetamethods};

const luaL_Reg Vector3Functions[] = {{"vec3", l_hpmvec3},
									 {"lerp", l_vec3_lerp},
									 {"slerp", l_vec3_slerp},
									 {"dot", l_vec3_dot2},
									 {"max", l_vec3_max},
									 {"min", l_vec3_min},
									 {"cross", l_vec3_cross},
									 {"reflection", l_vec3_reflection},
									 {"refraction", l_vec4_refraction},
									 {"tripleProduct", l_vec4_tripleProduct},
									 {"tangent", l_vec3_tangent},
									 {"forward", l_vec3_forward},
									 {"back", l_vec3_back},
									 {"right", l_vec3_right},
									 {"left", l_vec3_left},
									 {"up", l_vec3_up},
									 {"down", l_vec3_down},
									 {"one", l_vec3_one},
									 {"zero", l_vec3_zero},
									 {NULL, NULL}};

static const luaL_Reg Vec3Methods[] = {{"x", l_vec3_x},
									   {"y", l_vec3_y},
									   {"z", l_vec3_z},
									   {"length", l_vec3_length},
									   {"square", l_vec3_square},
									   {"normalize", l_vec3_normalize},
									   //									  {"makeUnitVector", l_vec4_length},
									   //{"dot", l_vec4_dot},
									   {"minComponent", l_vec3_min_component},
									   {"maxComponent", l_vec3_max_component},
									   {"maxAbsComponent", l_vec3_max_abs_component},
									   {"minAbsComponent", l_vec3_min_abs_component},
									   {NULL, NULL}};

static const luaL_Reg Vec3Metamethods[] = {{"__name", l_vec3_name},			{"__index", l_vec3_index},
										   {"__newindex", l_vec3_newindex}, {"__eq", l_vec3_eq},
										   {"__tostring", l_vec3_string},	{"__unm", l_vec3_unm},
										   {"__add", l_vec3_add},			{"__sub", l_vec3_sub},
										   {"__mul", l_vec3_mul},			{"__div", l_vec3_div},
										   {"__idiv", l_vec3_idiv},			{"__mod", l_vec3_mod},
										   {"__pow", l_vec3_pow},			{NULL, NULL}};

const CommonObject Vector3 = {"vec3", UdpMethods, UdpMetamethods};

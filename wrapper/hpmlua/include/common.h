#ifndef _COMMON_H_
#define _COMMON_H_ 1

#include <assert.h>
#include <stdarg.h>

#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"

#include <hpm.h>

/**
 * @struct common_evalue
 * @brief bind C enum as tables to Lua
 *
 * This is used with commonBindEnum().
 *
 * @see commonBindEnum
 */
typedef struct {
	const char *name; /*! the field name */
	int value;		  /*! the integer value */
} CommonEnum;

/**
 * @CommonObject
 * @brief bind a C object to Lua
 *
 * This is used with commonBindObject().
 *
 * @see commonBindObject
 */
typedef struct {
	const char *name;			 /*! metatable name */
	const luaL_Reg *methods;	 /*! methods (optional) */
	const luaL_Reg *metamethods; /*! metamethods (optional) */
} CommonObject;

/**
 * Wrapper for SDL object to Lua userdata. Some objects must be passed
 * so that they will not be freed, for instance SDL_GetWindowSurface() returns
 * a pointer that should not be freed while SDL_Surface objects has a __gc
 * that destroy the object.
 *
 * So any object should be passed as common_userdata so we know if we should
 * really delete the object or just let it live.
 */
typedef struct {
	int mustdelete; /*! tells if we should delete it */
	void *data;		/*! the data itself */
} CommonUserdata;

/**
 * Bind a C enum as a table to Lua.
 *
 * @param L the Lua state
 * @param tindex the table index where to set the table
 * @param tname the new table name as tindex new field
 * @param evalues the values
 */
void commonBindEnum(lua_State *L, int tindex, const char *tname, const CommonEnum *values);

/**
 * Bind an object to Lua.
 *
 * @param L the Lua state
 * @param def the object definition
 */
void commonBindObject(lua_State *L, const CommonObject *def);

/**
 * This function binds all functions to the already created table SDL.
 *
 * @param L the Lua state
 * @param functions the functions
 */
void commonBindLibrary(lua_State *L, const luaL_Reg *functions);

/**
 * Create a table and fills the functions in it.
 *
 * @param L the Lua state
 * @param functions the functions
 */
void commonNewLibrary(lua_State *L, const luaL_Reg *functions);

void *commonGetUserdata(lua_State *L, int index, const char *tname);

#define commonGetAs(L, index, name, type) ((type)luaL_checkudata(L, index, name))

#endif

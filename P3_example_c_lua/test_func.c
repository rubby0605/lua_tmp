#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* hellofunc.c (C) 2011 by Steve Litt
 * gcc -Wall -shared -fPIC -o power.so -I/usr/include/lua5.1 -llua5.1 hellofunc.c
 * Note the word "power" matches the string after the underscore in
 * function luaopen_power(). This is a must.
 * The -shared arg lets it compile to .so format.
 * The -fPIC is for certain situations and harmless in others.
 * On your computer, the -I and -l args will probably be different.
*/

#include <lua.h>                               /* Always include this */
#include <lauxlib.h>                           /* Always include this */
#include <lualib.h>                            /* Always include this */

static int isquare(lua_State *L){              /* Internal name of func */
	float rtrn = lua_tonumber(L, -1);      /* Get the single number arg */
	printf("Top of square(), nbr=%f\n",rtrn);
	lua_pushnumber(L,rtrn*rtrn);           /* Push the return */
	return 1;                              /* One return value */
}
static int icube(lua_State *L){                /* Internal name of func */
	float rtrn = lua_tonumber(L, -1);      /* Get the single number arg */
	printf("Top of cube(), number=%f\n",rtrn);
	lua_pushnumber(L,rtrn*rtrn*rtrn);      /* Push the return */
	return 1;                              /* One return value */
}


/* Register this file's functions with the
 * luaopen_libraryname() function, where libraryname
 * is the name of the compiled .so output. In other words
 * it's the filename (but not extension) after the -o
 * in the cc command.
 *
 * So for instance, if your cc command has -o power.so then
 * this function would be called luaopen_power().
 *
 * This function should contain lua_register() commands for
 * each function you want available from Lua.
 *
*/
int luaopen_power(lua_State *L){
	lua_register(
			L,               /* Lua state variable */
			"square",        /* func name as known in Lua */
			isquare          /* func name in this file */
			);  
	lua_register(L,"cube",icube);
	return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lua.h"
#include "lauxlib.h"
int main ( int argc, char **argv )
{
	int i;
	printf("Hello");
	return EXIT_SUCCESS;
}

static const struct luaL_reg mylib [] = {
      {"dir", get_test_value},
      {NULL, NULL}  /* sentinel (should endup with Null*/ 
}

int luaopen_mylib (lua_State *L) {
      luaL_openlib(L, "mylib", mylib, 0);
      return 1;
}



int get_test_value(lua_State *L){ 
	int i, num;
	printf("inside c, mat value is");
	for(i=0;i<=10;i++)
	{
		lua_pushvalue(L, i);
		printf("%d", 8);
	}
}
int get_globalint(lua_State *L, const char *var){
	int isnum, result;
	lua_getglobal(L, var);
	result = (int)lua_tointegerx(L,-1,&isnum);
	if(!isnum)
		error(L,"'%s'should be a number\n", var);
	lua_pop(L, 1); // remove the result
	return result;
}
static void stackDump (lua_State *L) {
      int i;
      int top = lua_gettop(L);
      for (i = 1; i <= top; i++) 
	  {  /* repeat for each level */
        int t = lua_type(L, i);
        switch (t) 
		{
    
          case LUA_TSTRING:  /* strings */
            printf("`%s'", lua_tostring(L, i));
            break;
    
          case LUA_TBOOLEAN:  /* booleans */
            printf(lua_toboolean(L, i) ? "true" : "false");
            break;
    
          case LUA_TNUMBER:  /* numbers */
            printf("%g", lua_tonumber(L, i));
            break;
    
          default:  /* other values */
            printf("%s", lua_typename(L, t));
            break;
    
        }
        printf("  ");  /* put a separator */
      }
      printf("\n");  /* end the listing */
}

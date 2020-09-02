static int l_dir (lua_State *L) {
       ...  /* as before */
    }

static const struct luaL_reg mylib [] = {
      {"dir", l_dir},
      {NULL, NULL}  /* sentinel */
    };
int luaopen_mylib (lua_State *L) {
      luaL_openlib(L, "mylib", mylib, 0);
      return 1;
    }


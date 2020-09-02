--this is a lua main script
local test = require("libtest.so")
mat_test = {}
for i = 1,100 do mat_test[i] = i*2 end
--lua_pushcfunction(L, get_test_value);
lua_setglobal(L, "mat_test");

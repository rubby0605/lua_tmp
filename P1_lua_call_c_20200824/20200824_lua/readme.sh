#lua_main.lua  readme.sh  test_func.c
gcc -I/usr/include/lua5.1/ -c -fPIC test_func.c -o test_func.o  -llua5.2 -lm

#gcc -I/usr/include/lua5.1 -o hello hello.c -llua5.1 -lm

gcc -I/usr/include/lua5.1 -shared -o libtest.so -fPIC test_func.c -llua5.2 -lm

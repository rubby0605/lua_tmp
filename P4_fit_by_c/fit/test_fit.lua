-- lua test script for wafer data regression 

    local path = "/home/qq/lintu/c/lib/GSL/gsl-2.6/fit/liblinreg.so"
    local f = loadlib(path, "test_sum")
	--local f = loadlib(path, "luaopen_socket")
	print "insdie lua"
	f(3.9,4.1)
	

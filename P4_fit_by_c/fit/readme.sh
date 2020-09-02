rm *.o
gcc -c -fPIC linear.c -o linear.o -lm -llapack -lblas
gcc -c -fPIC main.c -o main.o -lm -llapack -lblas
gcc *.o -L/home/qq/.local/ -shared -o liblinreg.so -lm -llapack -lblas
#gcc -Wall -std=c99 -c  band_solve.c -I/usr/include -o band_solve.o -lm -llapacke -lblas;
#gcc -Wall -std=c99 -Wfatal-errors -Werror -c  itrCalcT.c -I/usr/include -o itrCalcT.o -lm -llapacke -lblas;
#gcc *.o -L/home/qq/.local/ -llapack -lblas -lm -o code


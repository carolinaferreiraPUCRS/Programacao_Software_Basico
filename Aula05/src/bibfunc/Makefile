all:		main

main:		main.o bibfunc.o
		gcc -o main main.o bibfunc.o

main.o:		main.c bibfunc.h
		gcc -c main.c

bibfunc.o:	bibfunc.c bibfunc.h
		gcc -c bibfunc.c

clean:
		@rm -f *.o main

representation.o : representation.c representation.h
	gcc -c -Wall representation.c

main : main.c representation.h
	gcc -c -Wall main.c

compil :
	gcc -Wall main.c

exec :
	./a.out

all:
	mkdir out
	cc -std=c99 -Wall ./src/main.c -o ./out/my-own-lisp
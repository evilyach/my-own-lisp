all:
	[ -d "out" ] || mkdir out

	gcc -std=c99 -Wall -Werror \
		$(wildcard src/*.c) \
		$(wildcard lib/*) \
		-I include \
		-ledit \
		-lm \
		-o out/my-own-lisp

build:
	[ -f "lib/mpc.c" ] || wget https://raw.githubusercontent.com/orangeduck/mpc/master/mpc.c -P lib
	[ -f "lib/mpc.h" ] || wget https://raw.githubusercontent.com/orangeduck/mpc/master/mpc.h -P lib

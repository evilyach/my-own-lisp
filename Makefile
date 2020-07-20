all:
	[ -d "out" ] || mkdir out

	gcc -std=c99 -Wall -Werror \
		$(wildcard src/*.c) \
		-I include \
		-ledit \
		-o out/my-own-lisp

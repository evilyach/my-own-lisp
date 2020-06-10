all:
	[ -d "out" ] || mkdir out

	gcc -std=c99 -Wall \
		$(wildcard src/*.c) \
		-I include \
		-o out/my-own-lisp

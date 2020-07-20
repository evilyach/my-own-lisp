# My Own Lisp

My implementation of Lisp language using "Build Your Own Lisp" book by [Mr Daniel Holden](http://www.buildyourownlisp.com/) as a reference.

## Compiling

Beforehand, you need to resolve some dependencies. For Ubuntu and other Debian-based distributions, run

```bash
sudo apt install libedit-dev
```

Before compiling, you need to run
```bash
make build
```
It will download needed libraries.

To compile the interpreter, run

```bash
make
```

## Run

To run, while in `my-own-lisp` directory, run:

```bash

./out/my-own-lisp
```

## License
My Own Lisp is distributed under the MIT License.

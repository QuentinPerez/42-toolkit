42-toolkit	Libc
==========

## Tools unable

    - f_error/		"Treat return value"
    - f_string/		"It's funny"
    - f_memory/		"Function to play with memory"
    - error/		"Write error to file"
    - list/			"Double linked-list"
	- vector/		"Pointer array that can change size"
	- array/		"Struct array that can change size"
	- stack/		"Last-in-First-out container"
	- queue/		"First-in-First-out container"

## How to make libraries

    - ./make_lib
	- cd lib42

## Add to your Makefile

Variable:

	- DIR42    = lib42
	- CFLAGS  += -I./$(DIR42)/include
	- LDFLAGS += -L./$(DIR42) -l42
	- LIB42    = $(LIB42)/lib42.a

Add dependencies:

	- $(EXEC)	:	$(LIB42) ...
	- 			...

Rules:

	- $(LIB42)	:	force
	-  			make -C $(DIR42)
    -
	- relib		:
	- 			make re -C $(DIR42)
    -
	- force		:
	- 			true

## How add to your git project (at school) ?

Variable:

	- TOOLKIT    = 42-toolkit

Add dependencies:

	- $(DIR42)	:	$(TOOLKIT)
				cd $(TOOLKIT)/srcs/libc && ./make_lib && mv $(DIR42) ../../../

Rules:

	- $(TOOLKIT)	:
				git submodule add https://github.com/QuentinPerez/42-toolkit.git
				git submodule init

Update:

	- git submodule update


## Example

You can see Makefile example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/list/Makefile).

You can see Makefile example for school [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/school/Makefile).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

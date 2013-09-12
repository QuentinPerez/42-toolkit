42-toolkit	Libc
==========

## Tools unable

    - f_error/		"Treat return value"
    - f_string/		"Function to write"
	- list/			"Double linked-list"

## How to make libraries

    - ./make_lib

## Add to your Makefile

Variable:

	- DIR42    = lib42
	- CFLAGS  += -I./$(DIR42)/include
	- LDFLAGS += -L./$(DIR42) -l42
	- LIB42    = $(LIB42)/lib42.a

Rules:

	- $(LIB42)	:	force
	-  			make -C $(DIR42)
    -
	- relib		:
	- 			make re -C $(DIR42)
    -
	- force		:
	- 			true

## Example

You can see example for list [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/list).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

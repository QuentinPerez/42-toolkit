Libc
==========

# Unable
===

### Containers
    - list/			"Double linked-list"
	- vector/		"Pointer array that can change size"
	- array/		"Struct array that can change size"
	- stack/		"Last-in-First-out container"
	- queue/		"First-in-First-out container"
	- htable/		"Hash table"
	- rbtree/		"Red-Black Tree"
### Function
    - f_error/		"Treat return value with more skills"
    - f_string/		"Do you want play with char *?"
    - f_memory/		"Function to treat memory"
    - f_crypto/		"Function to encrypt-decrypt"
    - f_math/		"Math tools"
	- f_sort/		"Sort function"
### Tools
    - error/		"Write error to file"
	- timer/		"Timer in milliseconds"
	- getopt/		"Treat argv"
	- unit/			"42 unit testing"
	- matrix/

===

## How to make libraries ?
	- ./make_lib
	- cd lib42

===

## How add to your git project (at school) ?

	- git submodule add https://github.com/QuentinPerez/42-toolkit.git
	- git submodule init

#####Update:

	- git submodule update
===

## How compile lib42 in your own Makefile ?

#####Variables:

	- DIR42    = lib42
	- CFLAGS  += -I./$(DIR42)/include
	- LDFLAGS += -L./$(DIR42) -l42
	- LIB42    = $(LIB42)/lib42.a

#####Add dependencies:

	- $(EXEC)	:	$(LIB42) ...
	- 			...

#####Rules:

    - $(LIB42)	:	$(DIR42)
        make -C $(DIR42)

    - $(DIR42)	:	$(TOOLKIT)
        cd $(TOOLKIT)/srcs/libc && ./make_lib && mv $(DIR42) ../../../

    - $(TOOLKIT)	:
	   git submodule init
	   git submodule update
===


### Example link

[school's Makefile](https://github.com/QuentinPerez/42-toolkit/tree/master/doc/school/Makefile).

===

### License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

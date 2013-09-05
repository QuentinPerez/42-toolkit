42-toolkit	C
==========

## Tools unable

    - f_error/		"Treat return value"
    - f_string/		"Function to write"

## How to make libraries

    - ./make_lib
    - cp -R lib42/ ToYourWorkDirectory/

Add to your Makefile:

    - LDFLAGS   +=  -L./lib42 -l42
    - LIB42     =   lib42.a
    - $(LIB42)  :
    -           make -C lib42

And add dependency <code>$(LIB42)</code> with this line:

    - $(EXEC)   :   $(OBJ) $(LIB42)

## Example

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/c/lib).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

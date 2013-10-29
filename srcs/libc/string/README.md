42-toolkit	C String
==========

## Function

	- init(t_string *v_this, ui (*uf_realloc)(ui size))
	 /* This function initialize string */

	- print(t_string *v_this)
	 /* This function write data on screen */

	- print_fd(t_string *v_this, ui fd)
	 /* This function write data on fd */

	- print_memory(t_string *v_this, const char *name)
	 /* This function write data like hexedit */

	- dup(t_string *v_this)
	 /* This function return copy of string  */

	- capacity(t_string *v_this)
	 /* This function return capacity */

	- empty(t_string *v_this)
	 /* This function return true if size == 0 */

	- size(t_string *v_this)
	 /* This function return size */

	- clear(t_string *v_this)
	 /* This function clear string buffer */

	- add_str(t_string *v_this, const char *str)
	 /* This function add str to string buffer */

	- add_nstr(t_string *v_this, const char *str, ui size)
	 /* This function add size first byte to string buffer */

	- add_char(t_string *v_this, uc c)
	 /* This function add byte to string buffer */

	- add_nbr(t_string *v_this, ssize_t nbr)
	 /* This function add nbr to string buffer */

	- add_ptr(t_string *v_this, void *addr)
	 /* This function add address to string buffer */

	- add_nbr_base(t_string *v_this, ssize_t nbr, ui base)
	 /* This function add nbr in base to string buffer */

	- variadic(t_string *v_this, const char *fmt, ...)
	 /* This function like prinft */

	- variadic_list(t_string *v_this, const char *fmt, va_list *ap)
	 /* This function like printf too */

	- split(t_string *v_this, const char *charset)
	 /* This function cut srting buffer on substring */

	- erase(t_string *v_this, ui from, ui to)
	 /* This function erase data in interval (from, to) */

	- insert(t_string *v_this, const char *str, ui index)
	 /* This function insert str at index */

	- destroy(t_string *v_this)
	 /* This function clear and free memory */


## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/string).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

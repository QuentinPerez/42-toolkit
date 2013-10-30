42-toolkit	C String Function
==========

## Function

f_print.c:

	- uf_print_char(char c)
	/* Print 'c' on stdout */

	- uf_print_nbr(ssize_t nbr)
	/* Print value of 'nbr' on stdout */

	- uf_print_str(const char *str)
	/* Print the string 'str' on stdout */

	- uf_print_nbr_base(ssize_t nbr, ssize_t base)
	/* Print value of 'nbr' in 'base' on stdout */

	- uf_print_addr(void *addr)
	/* Print address 'addr' on stdout */

f_print_fd.c:

	- uf_print_char_fd(char c, ui fd)
	/* Print 'c' on out fd */

	- uf_print_nbr_fd(ui nbr, ui fd)
	/* Print value of 'nbr' on out fd */

	- uf_print_str_fd(const char *str, ui fd)
	/* Print the string 'str' on out fd */

	- uf_print_nbr_base_fd(ssize_t nbr, ssize_t base)
	/* Print value of 'nbr' in 'base' on out fd */

	- uf_print_addr_fd(void *addr)
	/* Print address 'addr' on out fd */

f_print_spec.c:	/* Experimental function */

	- uf_print_floating_nbr_fd(double number, ui digit, ui fd)
	/* Print floating value of 'number' on out fd */

	- uf_print_floating_nbr(double number, ui digit)
	/* Print floating value of 'number' on stdout */

	- uf_print_bits_fd(size_t value, size_t size, ui fd)
	/* Print value in bits on out fd */

	- uf_print_bits(size_t value, size_t size)
	/* Print value in bits on stdout */

f_print_variadic.c:

	- uf_print_variadic_fd(ui fd, const char *fmt, ...)
	  /* Like printf */

	- uf_print_variadic(const char *fmt, ...)
	  /* Like printf */

f_print_nstr.c:

	- uf_print_nstr_fd(const char *str, ui size, ui fd)
	  /* Print size bytes of str on out fd */

	- uf_print_nstr(const char *str, ui size)
	  /* Print size bytes of str on stdout */

f_str_tools.c:

	- uf_str_len(const char *str)
	/* Return lenght of string 'str' */

	- uf_print_in_base(char nbr, ui fd)
	/* Tools for print value in good base */

f_strcat.c:

	- uf_strcat(char *dest, const char *src)
	/* Append src to dest */

	- uf_strncat(char *dest, const char *src, size_t size)
	/* Append src to dest with specific size */

	- uf_strlcat(char *dest, const char *src, size_t size)
	/* man strlcat */

f_strcpy.c:

	- uf_strcpy(char *dest, const char *src)
	/* Copy src to dest */

	- uf_strncpy(char *dest, const char *src, size_t size)
	/* Copy src to dest with specific size */

	- uf_strlcpy(char *dest, const char *src, size_t size)
	/* man strlcpy */

f_strcmp.c:

	- uf_strcmp(char *dest, const char *src)
	/* Compare dest with src and return difference */

	- uf_strncmp(char *dest, const char *src, size_t size)
	/* Like strcmp but you compare length size */

f_strcasecmp.c:

	- uf_str_case_cmp(char *dest, const char *src)
	/* Like uf_strcmp (case insensitive) */

	- uf_str_case_ncmp(char *dest, const char *src, size_t size)
	/* Like uf_strncmp (case insensitive) */

f_char.c:

	- uf_to_lower(const uc c)
	/* Convert uppercase letter to lowercase */

	- uf_to_upper(const uc c)
	/* Convert lowercase letter to uppercase */

	- uf_is_lower(const uc c)
	/* Return true if letter is lowercase */

	- uf_is_upper(const uc c)
	/* Return true if letter is uppercase */

f_strdup.c:

	- uf_strdup(const char *str)
	/* Return copy of str */

f_space.c:

	- uf_is_space(const uc c)
	/* Return true if c is space */

	- uf_skip_space(const char *str)
	/* Increase str while is space */

## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/f_string).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

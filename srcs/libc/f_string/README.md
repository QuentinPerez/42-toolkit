42-toolkit	C String Function
==========

## Function

f_print.c:

	- uf_print_char(char c)
	/* Print 'c' on screen */

	- uf_print_nbr(ssize_t nbr)
	/* Print value of 'nbr' on screen */

	- uf_print_str(const char *str)
	/* Print the string 'str' on screen */

	- uf_print_nbr_base(ssize_t nbr, ssize_t base)
	/* Print value of 'nbr' in 'base' on screen */

	- uf_print_addr(void *addr)
	/* Print address 'addr' on screen */

f_print_fd.c:

	- uf_print_char_fd(char c, int fd)
	/* Print 'c' on out fd */

	- uf_print_nbr_fd(int nbr, int fd)
	/* Print value of 'nbr' on out fd */

	- uf_print_str_fd(const char *str, int fd)
	/* Print the string 'str' on out fd */

	- uf_print_nbr_base_fd(ssize_t nbr, ssize_t base)
	/* Print value of 'nbr' in 'base' on out fd */

	- uf_print_addr_fd(void *addr)
	/* Print address 'addr' on out fd */

f_str_tools.c:

	- uf_str_len(const char *str)
	/* Return lenght of string 'str' */

	- uf_print_in_base(char nbr, int fd)
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

f_char.c:

	- uf_to_lower(const uc c)
	/* Convert uppercase letter to lowercase */

	- uf_to_upper(const uc c)
	/* Convert lowercase letter to uppercase */

	- uf_is_lower(const uc c)
	/* Return true if letter is lowercase */

	- uf_is_upper(const uc c)
	/* Return true if letter is uppercase */

## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/f_string).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

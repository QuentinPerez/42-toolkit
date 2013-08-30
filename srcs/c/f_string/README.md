42-toolkit	C String Function
==========

## Function

f_print.c:

	- uf_print_char(char c)
	- Print 'c' on screen

	- uf_print_nbr(ssize_ti nbr)
	- Print value of 'nbr' on screen

	- uf_print_str(const char *str)
	- Print the string 'str' on screen

	- uf_print_nbr_base(ssize_t nbr, ssize_t base)
	- Print value of 'nbr' in 'base' on screen

	- uf_print_addr(void *addr)
	- Print address 'addr' on screen

f_print_fd.c:

	- uf_print_char_fd(char c, int fd)
	- Print 'c' on out fd

	- uf_print_nbr_fd(int nbr, int fd)
	- Print value of 'nbr' on out fd

	- uf_print_str_fd(const char *str, int fd)
	- Print the string 'str' on out fd

	- uf_print_nbr_base_fd(ssize_t nbr, ssize_t base)
	- Print value of 'nbr' in 'base' on out fd

	- uf_print_addr_fd(void *addr)
	- Print address 'addr' on out fd

f_str_tools.c:

	- uf_str_len(const char *str)
	- Return lenght of string 'str'

	- uf_print_in_base(char nbr, int fd)
	- Tools for print value in good base

## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/c/f_string).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

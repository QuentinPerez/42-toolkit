42-toolkit	C Error Function
==========

## Preview

<p align="center" >
	<img src="https://raw.github.com/QuentinPerez/42-toolkit/master/doc/images/m_error.png" alt="m_error" title="m_error">
</p>

## Function

m_error.c

	- m_error(const char *str_err, size_t ret_val)
	/* This function print str_err on stderr and return ret_val */

	- m_error_v(const char *str_err)
	/* This function print str_err on stderr */

	- m_error_infos(const char *infos)
	/* This function print infos on stdout */

## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/f_error).

## Warning

You should add <code>-DD_ERRORS_ON</code> to CFLAGS or compile in debug with [Makefile](https://github.com/QuentinPerez/42-toolkit/tree/master/srcs/Makefile)

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

Memory Function
==========

## Function

	- uf_memset(void *src, unsigned char c, size_t size)
	/* This function writes len bytes of value c */

	- uf_memcmp(const void *left, const void *right, size_t size)
	/* This function compare byte string form against byte string to */

	- uf_memcpy(void *to, const void *from, size_t size)
	/* This function copies n bytes memory "from" to "to" */

	- uf_print_memory(const void *to, ui size)
	/* This function print memory */

	- uf_free_tab(void **tab)
	/* This function delete all element of tab and delete tab */

	- uf_free_tab_fail(void **tab, ui current)
	/* This function delete element of tab and delete tab */

===
### How to use ?

You can see example [here](https://github.com/42School/42-toolkit/tree/master/examples/libc/f_memory).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

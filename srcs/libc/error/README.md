Error
==========

## Function

	- init(t_error *v_this, const char *file)
	  /* This function initialize t_error */

	- add(t_error *v_this, const char *error, bool ret)
	  /* This function append error to file or if file was NULL print on screen */
	  /* And return ret */

	- destroy(t_error *v_this)
	  /* This function free t_error */

===
### How to use ?

You can see [example](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/error).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

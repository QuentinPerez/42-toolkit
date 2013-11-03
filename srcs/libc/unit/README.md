42-toolkit	C Unit
==========

## Function

	- init(t_unit *v_this)
	  /* This function initialize t_unit */

	- add_context(t_unit *v_this, const char *name, bool (*init)(void *), bool (*destroy)(void *))
	  /* This function add a context */

	- add_test(t_unit *v_this, const char *context, const char *name, void (*test)(struct s_unit_test *))
	  /* This function add test into context */

	- assert(bool check)
	  /* This macro add error if needed */

	- console_run(t_unit *v_this)
	  /* This function launch user-interface */

	- destroy(t_unit *v_this)
	  /* This function free all memories used by t_unit */


## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/unit).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

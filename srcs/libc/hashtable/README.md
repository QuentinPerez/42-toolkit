42-toolkit	C Hashtable
==========

## Function

	- init(t_htable *v_this, ui number_prine, void (*f_delete)(void *data))
	  /* This function initialize t_htable */
	  /* WARNING Use a number prime */

	- add(t_htable *v_this, const char *key, void *data)
	  /* This function add new key */

	- get(t_htable *v_this, const char *key)
	  /* This function return element at key */

	- print(t_htable *v_this, bool (*uf_print)(t_htable_cell *data))
	  /* This function print all element */

	- destroy(t_htable *v_this)
	  /* This function destroy t_htable */

## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/hashtable).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

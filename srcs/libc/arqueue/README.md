Arqueue
==========

## Function

	- init(t_arqueue *v_this, size_t elem_size, size_t nb_elem);
	  /* This function initialize t_arqueue */

	- push(t_arqueue *v_this, void *data)
	  /* This function put element at the end */

	- pop(t_arqueue *v_this)
	  /* This function delete last element */

	- empty(t_arqueue *v_this)
	  /* This function return true if structure is empty */

	- destroy(t_arqueue *v_this)
	  /* This function free t_arqueue */

===
### How to use ?

You can see [example](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/arqueue).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

42-toolkit	C Vector
==========

## Function

	- init(t_vector *v_this, uint (*uf_realloc)(uint size), void (*uf_delete)(void *ptr))
	  /* This function init structure t_vector */

	- clear(t_vector *v_this)
	  /* This function remove all elements */

	- empty(const t_vector *v_this)
	  /* This function return if vector is empty */

	- size(const t_vector *v_this)
	  /* This function return size of vector */

	- capacity(const t_vector *v_this)
	  /* This function return capacity of vector */

	- push_back(t_vector *v_this, void *data)
	  /* This function push data at the end */

	- foreach(t_vector *v_this, bool (*funct)(void *ptr))
	  /* This function apply for lot of elements */

	- reserve(t_vector *v_this, uint new_size)
	  /* This function change capacity */

	- destroy(t_vector *v_this)
	  /* This function destroy t_vector */


## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/vector).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

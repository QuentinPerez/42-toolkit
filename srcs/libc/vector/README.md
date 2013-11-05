Vector
==========

## Function

	- init(t_vector *v_this, uint (*uf_realloc)(uint size), void (*uf_delete)(void *ptr))
	  /* This function initialize t_vector */

	- clear(t_vector *v_this)
	  /* This function remove all elements */

	- empty(const t_vector *v_this)
	  /* This function return true if vector is empty */

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

	- erase(t_vector *v_this, void *ptr)
	  /* This function remove ptr to vector and return data */

	- delete(t_vector *v_this, void *ptr)
	  /* This function delete ptr */

	- at(t_vector *v_this, uint index)
	  /* This function return index element */

	- data(t_vector *v_this)
	  /* This function data pointer */

	- front(t_vector *v_this)
	  /* This function first element */

	- back(t_vector *v_this,)
	  /* This function last element */

	- destroy(t_vector *v_this)
	  /* This function free t_vector */

===
## How to use ?

You can see [example](https://github.com/42School/42-toolkit/tree/master/examples/libc/vector).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

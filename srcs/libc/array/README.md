Array
==========

## Function

	- init(t_array *v_this, uint (*uf_realloc)(uint size), void (*uf_delete)(void *ptr))
	  /* This function initialize t_array */

	- clear(t_array *v_this)
	  /* This function remove all elements */

	- empty(const t_array *v_this)
	  /* This function return true if array is empty */

	- size(const t_array *v_this)
	  /* This function return size of array */

	- capacity(const t_array *v_this)
	  /* This function return capacity of array */

	- push_back(t_array *v_this, void *data)
	  /* This function push element at the end */

	- foreach(t_array *v_this, bool (*funct)(void *ptr))
	  /* This function apply "funct" foreach elements */

	- delete_if(t_array *v_this, bool (*ft_cmp)(void *d1, void *d2), void *data);
	  /* This function delete element, if ft_cmp return true */

	- resize(t_array *v_this, ui size)
	  /* This function resize array */

	- data(t_array *v_this, TYPEOF)
	  /* This function data pointer */
	  /* WARNING here you pass typeof struct you can (must) see example */

	- at(t_array *v_this, ui index, TYPEOF)
	  /* This function pointer to index */
	  /* WARNING here you pass typeof struct you can (must) see example */

	- destroy(t_array *v_this)
	  /* This function free t_array */

===

### How to use ?

You can see [example](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/array).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

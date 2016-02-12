List
==========

## Function

	- init(t_list *v_this, void (*v_funct_destroy)(void *data))
	  /* This function initialize t_list */

	- empty(const t_list *v_this)
	  /* This function return true if list is empty */

	- size(const t_list *v_this)
	  /* This function return size of list */

	- begin(const t_list *v_this)
	  /* This function return begin of list */

	- end(const t_list *v_this)
	  /* This function return end of list */

	- erase(t_list *v_this, t_list_cell *cell, void **data)
	  /* This function remove cell to list and put element in data */

	- get_cell(t_list *list, ui cell_at)
	  /* This function get one cell specified by his position */

	- delete(t_list *v_this, t_list_cell *delete)
	  /* This function delete cellule and call funct_destroy for data */

	- print_addr(const t_list *v_this)
	  /* This function print addr of lot of cellule */

	- push_back(t_list *v_this, void *data)
	  /* This function push data at the end */

	- pop_back(t_list *v_this)
	  /* This function delete last data */

	- push_front(t_list *v_this, void *data)
	  /* This function push data at the begin */

	- pop_front(t_list *v_this)
	  /* This function delete first data */

	- insert(t_list *v_this, t_list_cell *position, void *data)
	  /* This function insert data before the cell at the specified position */

	- back(t_list *v_this)
	  /* This function return last data */

	- front(t_list *v_this)
	  /* This function return the first data */

	- split(t_list *v_this, t_list_cell *split_at, t_list *new_list)
	  /* This function split a list in 2 part and assign the new part to new_list */

	- foreach(t_list *v_this, bool (*funct)(void *value))
	  /* This function apply for lot of elements */

	- reverse(t_list *v_this)
	  /* This function reverse list */

	- splice(t_list *v_this, t_list_cell *position,
			 t_list *other_list, t_list_interval *other_interval);
	  /* This function transfers elements from other_list to v_this before position */

	- delete_if(t_list *v_this, bool (*cmp)(void *data, void *value), void *value)
	  /* This function delete element if cmp return true */

	- clear(t_list *v_this)
	  /* This function remove all elements */

	- destroy(t_list *v_this)
	  /* This function free list */

===
### How to use ?

You can see [example](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/list).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

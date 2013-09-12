42-toolkit	C List
==========

## Function

	- init(t_list *v_this, void (*v_funct_destroy)(void *data))
	  /* This function init structure t_list */

	- empty(const t_list *v_this)
	  /* This function return if list is empty */

	- size(const t_list *v_this)
	  /* This function return size of list */

	- begin(const t_list *v_this)
	  /* This function return begin of list */

	- end(const t_list *v_this)
	  /* This function return end of list */

	- erase(t_list *v_this, t_cell *erase)
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

	- back(t_list *v_this)
	  /* This function return last data */

	- front(t_list *v_this)
	  /* This function return the first data */

	- foreach(t_list *v_this, bool (*funct)(void *value))
	  /* This function apply for lot of elements */

	- reverse(t_list *v_this)
	  /* This function reverse list */

	- remove(t_list *v_this, bool (*cmp)(void *data, void *value), void *value)
	  /* This function remove element if cmp return true */

	- clear(t_list *v_this)
	  /* This function remove all elements */

	- destroy(t_list *v_this)
	  /* This function destroy list */

## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/list).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

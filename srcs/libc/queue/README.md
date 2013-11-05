Queue
==========

## Function

	- init(t_queue *v_this, void (*funct_destroy)(void *data))
	  /* This function initialize t_queue */

	- push(t_queue *v_this, void *data)
	  /* This function put element at the end */

	- pop(t_queue *v_this)
	  /* This function delete first element */

	- back(t_queue *v_this)
	  /* This function return last element */

	- front(t_queue *v_this)
	  /* This function return first element */

	- clear(t_queue *v_this)
	  /* This function clear and delete all element */

	- empty(t_queue *v_this)
	  /* This function true if structure is empty */

	- size(t_queue *v_this)
	  /* This function return number element */

	- foreach(t_queue *v_this, bool (*funct)(void *data))
	  /* This function apply funct for all element */

	- destroy(t_queue *v_this)
	  /* This function free t_queue */

===
### How to use ?

You can see [example](https://github.com/42School/42-toolkit/tree/master/examples/libc/queue).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

42-toolkit	C Stack
==========

## Function

	- init(t_stack *v_this, void (*funct_destroy)(void *data))
	  /* This function init structure t_stack */

	- destroy(t_stack *v_this)
	  /* This function clear and reset t_stack */

	- push(t_stack *v_this, void *data)
	  /* This function put element at the end */

	- pop(t_stack *v_this)
	  /* This function delete last element */

	- clear(t_stack *v_this)
	  /* This function clear and delete all element */

	- top(t_stack *v_this)
	  /* This function return last element */

	- empty(t_stack *v_this)
	  /* This function true if structure is empty */

	- size(t_stack *v_this)
	  /* This function return number element */


## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/stack).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

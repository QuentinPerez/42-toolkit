Lock
==========

## Function


	- init(t_lock *v_this, void *data, e_lock_type type)
	  /* This function initialize t_lock with the data when you want to protect */

	- lock(t_lock *v_this, void **data)
	  /* This function lock the mutex variable and set data */

	- release(t_lock *v_this, void **data)
	  /* This function release the mutex variable and data == NULL */

	- destroy(t_lock *v_this)
	  /* This function destroy t_lock */

===
### How to use ?

You can see [example](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/lock).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

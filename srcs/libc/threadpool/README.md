Threadpool
==========

## Function

	- init(t_threadpool *v_this, size_t nb_threads);
	  /* This function initialize t_threadpool and create nb thread */

	- add_task(t_threadpool *v_this, t_threadpool_task *task);
	  /* This function add function to tasks queue */

	- destroy(t_threadpool *v_this)
	  /* This function free t_threadpool and delete all thread */

===
### How to use ?

You can see [example](https://github.com/42School/42-toolkit/tree/master/examples/libc/threadpool).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

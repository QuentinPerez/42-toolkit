Matrix
==========

## Function

	- init(t_matrix *v_this, ui c, ui r);
	  /* This function initializes a t_matrix */

	- destroy(t_matrix *v_this);
	  /* This function free a t_matrix */

	- sum(t_matrix *v_this, t_matrix *m1, t_matrix *m2);
	  /* This function does the sum of two t_matrix */

	- sub(t_matrix *v_this, t_matrix *m1, t_matrix *m2);
	  /* This function does the sub of two t_matrix */

	- mul(t_matrix *v_this, t_matrix *m1, t_matrix *m2);
	  /* This function does the mul of two t_matrix */

	- div(t_matrix *v_this, t_matrix *m1, t_matrix *m2);
	  /* This function does the div of two t_matrix */

	- print(const t_matrix *v_this, const char *name);
	  /* This function print matrix */

===
### How to use ?

You can see [example](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/matrix).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

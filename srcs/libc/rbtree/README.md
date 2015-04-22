Rbtree
==========

## Function

	- init(t_rbtree *v_this, int (*f_cmp)(void *d1, void *d2), void (*f_del)(void *data));
	  /* This function initializes a t_rbtree */

	- find(t_rbtree *v_this, void *find);
	  /* This function returns node with if the data match */

	- root(t_rbtree *v_this);
	  /* This function returns root node */

	- empty(const t_rbtree *v_this);
	  /* This function returns true if the structure is empty */

	- foreach_inorder(t_rbtree *v_this, t_rbcell *node, void *data, bool (*funct)(void *node, void *data));
	  /* This function apply funct foreach node */

	- foreach_preorder(t_rbtree *v_this, t_rbcell *node, void *data, bool (*funct)(void *node, void *data));
	  /* This function apply funct foreach node */

	- foreach_postorder(t_rbtree *v_this, t_rbcell *node, void *data, bool (*funct)(void *node, void *data));
	  /* This function apply funct foreach node */

	- insert(t_rbtree *v_this, void *v_data);
	  /* This function insert data */

	- erase(t_rbtree *tree, t_rbcell *node);
	  /* This function erase node in rbtree and return data */

	- delete(t_rbtree *tree, t_rbcell *node);
	  /* This function erase node in rbtree and delete data */

	- destroy(t_rbtree *v_this);
	  /* This function free a t_rbtree */

===

### How to use ?

You can see [example](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/rbtree).

===
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

Contributing
======

## Code

### Coding style

Please refer to existing code and try to keep the same coding style as the one currently used.

For any questions use the [issues tracker](https://github.com/QuentinPerez/42-toolkit/issues)

Remenber: **a function should do one thing, and it should do it well**.

You can (**must**) see [norme 42](https://docs.google.com/file/d/0Byas2-wgCXhnMTR0ak5XeTNEalE/edit?usp=sharing).

LIB42 Rules:

	- count += 1			/* WRONG */
	- count = count + 1		/* RIGHT */

	- if (!test())			/* WRONG */
	- if (test() == false)	/* RIGHT */

	- uf_function			/* undefined function it does not belong to the library */
	- tf_funtion			/* function for the unit test */
	- f_struct_function		/* function that is part of the library */

## Commits

### What should I know?

A few things:

*If you're intent to implement a new feature, it is better to talk about it, to the [tracker](https://github.com/QuentinPerez/42-toolkit/issues) before.
* Usually you're not 100% sure if what you're doing should be in the project or not, then [just ask](https://github.com/QuentinPerez/42-toolkit/issues)!
* Please never commit code that cannot compile, even if this commit is in the middle of your branch and no one will ever notice it. Please.
* **A commit has to do only one thing, and has to do it well**
* **A branch name has to state clearly what it does**

### How do I commit?

By following these simple steps:

1. [Fork](https://github.com/QuentinPerez/42-toolkit/fork) 42-toolkit's repository
2. Create your branch (`git checkout -b my-branch-where-I-did-smth`)
3. If you wish, add yourself to the contributors in [README.md](https://github.com/QuentinPerez/42-toolkit#contributors) (`* [firstname lastname](https://github.com/yournick)`).
4. Code and commit your changes.
5. Push to your branch (`git push origin my-branch-where-I-did-smth`).
6. Create your new Pull Request.

You've shared your work, thank you!

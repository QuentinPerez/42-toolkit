Contributing
======

## Code

#### Coding style

===
Please **refer to existing code** and try to keep the same coding style as the one currently used.

For any questions use the [issues tracker](https://github.com/QuentinPerez/42-toolkit/issues)

#####Remember:
	A function should do one thing, and it should do it well.

You can (**must**) see [norme 42](https://docs.google.com/file/d/0Byas2-wgCXhnMTR0ak5XeTNEalE/edit?usp=sharing).

####LIB42 Rules:

	- count += 1			/* WRONG */
	- ++count				/* WRONG */
	- count++ 				/* WRONG */
	- count = count + 1		/* RIGHT */

	- if (test())			/* WRONG */
	- if (!test())			/* WRONG */
	- if (test() == false)	/* RIGHT */

	- uf_function			/* undefined function it does not belong to the library */
	- tf_function			/* function for the unit test */
	- f_struct_function		/* function that is part of the library *

===
## Commits

### What should I know?

#####A few things:

*If you're intent to implement a new feature, it is better to talk about it, to the [tracker](https://github.com/QuentinPerez/42-toolkit/issues) before.
* Usually you're not 100% sure if what you're doing should be in the project or not, then [just ask](https://github.com/QuentinPerez/42-toolkit/issues)!
* Please never commit code that cannot compile, even if this commit is in the middle of your branch and no one will ever notice it. Please.
* **A commit has to do only one thing, and has to do it well**
* **A branch name has to state clearly what it does**

#####42Student
######Github name
`FistnameLastname` Why ? ... Because we are not 10 years old.
#####Others
`You are welcome :)`


### How do I commit?

=======
[A successful Git branching model](http://nvie.com/posts/a-successful-git-branching-model/)

####Branch:
**Master** - Releases

**Develop** - New features

**Bugfix** - Bug fix #issues

**Norme** - Fix norme

**English** - Fix mistakes

#####By following these simple steps:

1. [Fork](https://github.com/QuentinPerez/42-toolkit/fork) 42-toolkit's repository
2. Create your branch (`git checkout -b my-branch-where-I-did-smth`)
3. Code and commit your changes.
4. Push to your branch (`git push origin my-branch-where-I-did-smth`).
5. Create your new Pull Request on **Develop**, **Bugfix**, **English** or **Norme** branch.
6. **NEVER BRANCH MASTER NEVER**

You've shared your work, thank you!

42-toolkit	header
==========

## Preview

<p align="center" >
	<img src="https://raw.github.com/QuentinPerez/42-toolkit/master/doc/images/header-42.png" alt="header" title="header">
</p>

## Description

This plugin generate header like 42.

When you open <code>newfile.c</code> this plugin put header on the top.

# Env

	- Add to your profile_file (.bashrc | .zshrc | .profile | ...).

    - export MAIL42=YourMail
    - export USER42=YourUser

	- reset your prompt and like it

## Installation with vundle

### For lazy people who want to copy/paste commands :

Save the make_header.vim in your home, end then run the followings command : (make sure you have vundle installed)

	mkdir ~/.vim/bundle/42header
	mkdir ~/.vim/bundle/42header/plugin
	mv ~/make_header.vim ~/.vim/bundle/42header/plugin/

And then add to your .vimrc file the following line to add the bundle :

	Bundle '42header'

Enjoy !

### For people who want to manage the name they use for their bundle :

To install this plugin if you are using the plugin manager vundle simply create a directory under ~/.vim/bundle named 42header for example.

Create a directory in it named plugin.

Copy the make_header.vim in it.

In your .vimrc add the bundle :
	
	Bundle '42header'

And Enjoy !

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

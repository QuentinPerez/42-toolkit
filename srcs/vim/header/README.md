42-toolkit	header
==========

## Preview

<p align="center" >
	<img src="https://raw.github.com/QuentinPerez/42-toolkit/master/doc/images/header-42.png" alt="header" title="header">
</p>

## Description

This plugin generate header like 42.

When you open `newfile.c` this plugin put header on the top.

# Env

Append the following lines into your config shell file `.bashrc, .zshrc, .profile | ...`

```bash
export MAIL42=YourMail
export USER42=YourUser
```

Open a new terminal

```console
$> env
...
MAIL42=YourMail
USER42=YourUser
...
```

## Installation with vundle

### For lazy people who want to copy/paste commands :

Move `make_header.vim` in your `$HOME`
```console
$> mkdir -p ~/.vim/bundle/42header/plugin
$> mv ~/make_header.vim ~/.vim/bundle/42header/plugin/
```

And append `Bundle '42header'` into your `~/.vimrc`

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

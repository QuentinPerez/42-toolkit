42-toolkit	speed_open
==========

## Preview

<p align="center" >
	<img src="https://raw.github.com/QuentinPerez/42-toolkit/master/doc/images/speed_open.png" alt="speed_open" title="speed_open">
</p>

# Description

This plugin switch between your .h and .c

# How to install

Add to your .vimrc

    - let mapleader = ","
    - nnoremap <leader>h :call Speed_open("vs")<cr>
    - nnoremap <leader>H :call Speed_open("sp")<cr>

After open file(.c | .h) and if file(.c | .h) exist press in <code>NORMAL</code> mode <code>,h</code> or <code>,H</code>

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

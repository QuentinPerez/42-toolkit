42-toolkit	speed_open
==========

# Description

This plugin switch between your `header` file and your `c` file

# How to install ?

Append the following line into `~/.vimrc`

```vimscript
let mapleader = ","
nnoremap <leader>h :call Speed_open("vs")<cr>
nnoremap <leader>H :call Speed_open("sp")<cr>
```

And now open a file, press on `ESC` and `,h` or `ESC` and `,H`  
## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).

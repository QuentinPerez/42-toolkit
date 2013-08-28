"
" <This plugin split between .h and .c>
" Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
"
" This file is part of 42-toolkit.
"
" 42-toolkit is free software: you can redistribute it and/or modify
" it under the terms of the GNU General Public License as published by
" the Free Software Foundation, either version 3 of the License, or
" (at your option) any later version.
"
" This program is distributed in the hope that it will be useful,
" but WITHOUT ANY WARRANTY; without even the implied warranty of
" MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
" GNU General Public License for more details.
"
" You should have received a copy of the GNU General Public License
" along with this program.  If not, see <http://www.gnu.org/licenses/>.
"

function!	Speed_open(split)
	let l:extension = ""
	if expand('%:e') ==? "c"
		let l:extension = ".h"
	endif
	if expand('%:e') ==? "h"
		let l:extension = ".c"
	endif
	let l:current_extension = "\\." . expand('%:e')
	let	l:file_open = substitute(expand('%:f'), l:current_extension, l:extension, "g")
	let l:cmd = '/usr/bin/basename "' . l:file_open . '" 2> /dev/null | tr -d "\n"'
	let l:file_open = system(l:cmd)
	for dir in ["." , ".."]
		let l:cmd = "find " . dir . " -type f -name " . l:file_open . " 2> /dev/null | tr '\n' ' ' | awk '{print $1}' | tr -d '\n'"
		let l:file = system(l:cmd)
		if filereadable(l:file)
			exe ":" . a:split . " " . l:file
			return
		endif
	endfor
	echo "No such file " . l:file_open . "."
endfunction

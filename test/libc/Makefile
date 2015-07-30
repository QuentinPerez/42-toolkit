#
# <Makefile for example directory>
# Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
#
# This file is part of 42-toolkit.
#
# 42-toolkit is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

DIR42	=	lib42
CMDIR	=	cmocka
CMLIB	=	$(CMDIR)/build/src/libcmocka.a
CFLAGS	+=	-Wextra -Wall -Werror -I./$(DIR42)/include -I./$(CMDIR)/include
LDFLAGS	+=	-L./$(DIR42) -l42 -lpthread $(CMLIB)
DEBUG	=	-g3 -fno-inline

LISTDIR	=	$(shell find ./* -maxdepth 0 -type d -not -path "./lib42" -not -path "./cmocka")

LIB42	=	$(DIR42)/lib42.a

EXELIST	=	$(addsuffix /a.out, $(LISTDIR))

.SILENT:

all	:	$(CMLIB) $(DIR42) $(LIB42) $(EXELIST)

%/a.out		:	$(subst /a.out,/src/main.c,%/a.out)
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
		printf '\033[1;31m%s \033[1;35m%s \033[1;33m%s\n\033[0m' "Linking C executable" "$@" "$(CC)"


$(LIB42)	:	force
			make -C $(DIR42)

$(CMDIR)	:
	git submodule init
	git submodule update

$(CMLIB)	:	$(CMDIR)
	mkdir -p $(CMDIR)/build && cd $(CMDIR)/build && cmake .. -DWITH_STATIC_LIB=on && make

clean	:
		/bin/rm	-fr $(DIR42) $(EXELIST)
		printf '\033[1;34m%s\n\033[0m' "Clean all project"

debug	:
		/bin/rm	-fr $(EXELIST)
		make debug -C $(DIR42)
		make

r		:
		/bin/rm	-fr $(EXELIST)
		make

re		:	clean all

relib	:
		make re -C $(DIR42)

$(DIR42)	:
			./configure

force	:
		true

travis	:
	for EXE in $(LISTDIR);						\
	do											\
		echo "\033[32m----Testing $$EXE\033[m";	\
		$$EXE/a.out;							\
	done

.PHONY:	clean re relib

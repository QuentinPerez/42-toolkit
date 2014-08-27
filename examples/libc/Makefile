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

CC		=	clang
DIR42	=	lib42
CFLAGS	+=	-Wextra -Wall -Werror -I./$(DIR42)/include -DD_ERRORS_ON
LDFLAGS	+=	-L./$(DIR42) -l42 -lpthread
DEBUG	=	-g3 -fno-inline -DD_ERRORS_ON

LISTDIR	=	array			\
			arqueue			\
			error			\
			f_crypto		\
			f_error			\
			f_math			\
			f_memory		\
			f_sort			\
			f_string		\
			getopt			\
			htable			\
			list			\
			queue			\
			stack			\
			string			\
			timer			\
			threadpool		\
			unit			\
			vector			\
			matrix			\
			lock			\
			rbtree

LIB42	=	$(DIR42)/lib42.a

EXELIST	=	$(addsuffix /a.out, $(LISTDIR))

.SILENT:

all	:	$(DIR42) $(LIB42) $(EXELIST)

%/a.out		:
		$(CC) $(CFLAGS) -o $@ $(subst /a.out,,$@/src/main.c) $(LDFLAGS)
		printf '\033[1;31m%s \033[1;35m%s \033[1;33m%s\n\033[0m' "Linking C executable" "$@" "$(CC)"


$(LIB42)	:	force
			make -C $(DIR42)

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

.PHONY:	clean re relib

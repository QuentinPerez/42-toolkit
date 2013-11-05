#
# <Makefile template>
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
TOOLKIT	=	42-toolkit
DIR42	=	lib42
CFLAGS	+=	-Wextra -Wall -Werror -I./$(DIR42)/include
LDFLAGS	+=	-L./$(DIR42) -l42
DEBUG	=	-g3 -fno-inline -DD_ERRORS_ON

NB_CORE =	1
UNAME	:=	$(shell uname -s)
ifeq ($(UNAME), Linux)
	NB_CORE	:=	$(shell grep -c ^processor /proc/cpuinfo)
endif
ifeq ($(UNAME), Darwin)
	NB_CORE	:=	$(shell sysctl -n hw.ncpu)
endif

OBJDIR	=	.objs
LISTDIR	=	src

DIRSRC	=	src

EXEC	=	a.out
LIB42	=	$(DIR42)/lib42.a

SRC		=	$(DIRSRC)/main.c

OBJ		=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

.SILENT:

$(addprefix $(OBJDIR)/, %.o)	:	%.c
								$(CC) $(CFLAGS) -o $@ -c $<
								printf '\033[0;32mBuilding C Object $@\n\033[0m' "Building C Object $@"

$(EXEC)	:	$(DIR42) $(OBJDIR) $(LIB42) $(OBJ)
		$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)
		printf '\033[1;31m%s \033[1;35m%s \033[1;33m%s\n\033[0m' "Linking C executable" "$(EXEC)" "$(CC)"

$(LIB42)	:	force
			make -j$(NB_CORE) -C $(DIR42)

clean	:
		/bin/rm	-fr $(OBJDIR) $(DIR42)
		printf '\033[1;34m%s\n\033[0m' "Clean project $(EXEC)"

fclean	:	clean
		/bin/rm -fr $(EXEC)
		printf '\033[1;34m%s\n\033[0m' "Fclean project $(EXEC)"

re		:	fclean all

debug	:	CFLAGS += $(DEBUG)
debug	:	re
		printf '\033[1;31m%s \033[1;35m%s\n\033[0m' "Debug version" "$(DEBUG)"

analyze	:	CFLAGS += --analyze
analyze	:	re

every	:	CFLAGS += -Weverything
every	:	re
		printf '\033[1;33m%s\n\033[0m' "Good job !"

relib	:
		make re -j$(NB_CORE) -C $(DIR42)

all		:	$(EXEC)

$(DIR42)	:	$(TOOLKIT)
			cd $(TOOLKIT)/srcs/libc && ./make_lib && mv $(DIR42) ../../../

$(TOOLKIT)	:
			git submodule add https://github.com/42School/42-toolkit.git
			git submodule init

$(OBJDIR)	:
		/bin/mkdir $(OBJDIR);			\
		for DIR in $(LISTDIR);			\
		do								\
			/bin/mkdir $(OBJDIR)/$$DIR;	\
		done							\

help	:
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "clean"	"Cleaning all object"
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "fclean"	"Cleaning all object and executable"
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "debug"	"Add debug flags"
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "re"		"Deleting all object and build"
		printf '\n'
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "analyze"	"Analyze code but compile nothing"
		printf '\033[1;34m%s\t\033[0m⇒ %s\n' "every"	"God code"

force	:
		true

.PHONY:	clean fclean re debug analyze every relib

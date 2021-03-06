# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/13 23:46:29 by ggilaber          #+#    #+#              #
#    Updated: 2015/11/16 18:25:01 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = another

SRCSFILES = main.cpp\
				class/Pieton.cpp\
				class/Foule.cpp\
				class/Stress.cpp\
				namespace/geometrie.cpp

SRCPATH = src
OBJPATH = obj
CC = clang++
INCLUDES =  -I inc\
			-I src/class\
			-I src/namespace\
			-I SFML/include

LDENV = DYLD_FRAMEWORK_PATH="SFML/Frameworks"
# export DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks"

LIBS =	-framework sfml-graphics -framework sfml-window -framework sfml-system\
		-F SFML/Frameworks -lncurses
CFLAGS = -Werror -Wall -Wextra -O2

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJ = $(SRC:$(SRCPATH)/%.cpp=$(OBJPATH)/%.o)


all: $(NAME)

$(NAME): ./SFML $(OBJ)
	@echo "Compiling all"
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBS)

$(OBJPATH)/%.o : $(SRCPATH)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

rmsfml:
	rm -rf SFML
./SFML:
	curl -O "http://mirror0.sfml-dev.org/files/SFML-2.2-osx-clang-universal.tar.gz" 
	mkdir SFML
	tar -xzf SFML-2.2-osx-clang-universal.tar.gz -C SFML --strip-components=1
	mv SFML/extlibs/freetype.framework SFML/Frameworks/
	rm -rf "SFML-2.2-osx-clang-universal.tar.gz"

ldenv:
	@echo export $(LDENV)

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/06/27 22:02:00 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

# Dir vars

SRCDIR = .

INCLUDESDIR = .

# Files vars

MAIN = main.cpp

CFILES = Interface.class.cpp CPU.cpp

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

HFILES = Interface.class.hpp CPU.hpp

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -O3 -Wall -Werror -Wextra

INCLUDEFLAGS = -I $(INCLUDESDIR)/

LIB = -lncurses

FLAGS = $(ERRORFLAGS) $(INCLUDEFLAGS)

CC = clang++

# Rules

all: $(NAME)

$(NAME): $(OBJ)
			@$(CC) -g $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)

fclean: clean
			@rm -f $(NAME)

%.o: %.cpp
			$(CC) $(FLAGS) -g -o $@ -c $< 

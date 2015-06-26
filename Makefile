# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 14:10:51 by kperreau          #+#    #+#              #
#    Updated: 2015/06/24 21:35:00 by kperreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game

# Dir vars

SRCDIR = src

INCLUDESDIR = includes

# Files vars

MAIN = main.cpp

CFILES = 

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

HFILES = 

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

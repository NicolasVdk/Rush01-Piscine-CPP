NAME = ft_gkrellm

# Dir vars

SRCDIR = .

INCLUDESDIR = .

# Files vars

MAIN = main.cpp

CFILES = Interface.class.cpp CPU.cpp Name.cpp Date.cpp Network.cpp RAM.cpp Os_info.cpp

SRC = $(patsubst %, $(SRCDIR)/%, $(CFILES))

OBJ = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

HFILES = Interface.class.hpp CPU.hpp Name.hpp Date.hpp Network.hpp RAM.hpp Os_info.hpp

MLX = -L./mlx -framework OpenGL -framework AppKit -lmlx

HEADERS = $(patsubst %, $(INCLUDESDIR)/%, $(HFILES))

# COMPILATION

ERRORFLAGS = -O3 -Wall -Werror -Wextra -march=native

INCLUDEFLAGS = -I $(INCLUDESDIR)/

LIB = -lncurses

FLAGS = $(ERRORFLAGS) $(INCLUDEFLAGS)

CC = clang++

# Rules

all: $(NAME)

$(NAME): $(OBJ)
			$(CC) -g $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)

re: fclean all

clean:
			@rm -f $(OBJ)

fclean: clean
			@rm -f $(NAME)

%.o: %.cpp
			$(CC) $(FLAGS) -g -o $@ -c $< 

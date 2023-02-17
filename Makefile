# - MACRO -

NAME = server

NAME2 = client

GCC = gcc

FLAGS = -Wall -Wextra -Werror

# - SRC -

SRC_SERVE = server.c

SRC_CLIENT = client.c

OBJS_SERVE = ${SRC_SERVE:.c=.o}

OBJS_CLIENT = ${SRC_CLIENT:.c=.o}

# - COMPILATION -

all : $(NAME) $(NAME2)

bonus : all

NAME : $(OBJS_SERVE)
	$(GCC) $(FLAGS) $(OBJS_SERVE) -o $(NAME)

NAME2 : $(OBJS_CLIENT)
	$(GCC) $(FLAGS) $(OBJS_CLIENT) -o $(NAME2)

# - CLEAN -

clean :
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVE)

fclean : clean
	rm -rf $(NAME) $(NAME2)

re : fclean all
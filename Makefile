NAME := server
NAME2 := client
CFLAGS := -Wall -Werror -Wextra

SRC1 = utils.c \
       server.c

SRC2 = utils.c \
       client.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all:	$(NAME) $(NAME2)

$(NAME):	$(OBJ1) $(SRC1)
	gcc $(CFLAGS) $(OBJ1) -o $(NAME)
$(NAME2):	$(OBJ2) $(SRC2)
	gcc $(CFLAGS) $(OBJ2) -o $(NAME2)

clean:
	rm -f $(OBJ1) $(OBJ2)
fclean: clean
	rm -f $(NAME) $(NAME2)
re:
	fclean all
.PHONY:	re clean fclean all

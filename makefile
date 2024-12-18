NAME = "getnextline"
cc = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c \
	get_next_line_utils.c

OBJ = $(SRC = .o = .c)

$(NAME): $(OBJ)

	cc get_next_line.c get_next_line_utils.c -Wall -Wextra -Werror -o get_next_line
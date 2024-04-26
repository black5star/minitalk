CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJC_s = $(SRCS_SERVER:.c=.o)
OBJC_c = $(SRCS_CLIENT:.c=.o)
SRCS_CLIENT_BONUS = client_bonus.c
SRCS_SERVER_BONUS = server_bonus.c
OBJC_C_B = $(SRCS_CLIENT_BONUS:.c=.o)
OBJC_S_B = $(SRCS_SERVER_BONUS:.c=.o)
NAME = server client
NAME_BONUS = server_bonus client_bonus

$(NAME): $(OBJC_c) $(OBJC_s) $(SRCS_CLIENT) $(SRCS_SERVER)
	@$(CC) $(FLAGS)  $(SRCS_SERVER) -o server
	@$(CC) $(FLAGS) $(SRCS_CLIENT) -o client
	@echo "server and client are ready"

$(NAME_BONUS): $(OBJC_C_B) $(OBJC_S_B) $(SRCS_CLIENT_BONUS) $(SRCS_SERVER_BONUS)
	@$(CC) $(FLAGS)  $(SRCS_SERVER_BONUS) -o server_bonus
	@$(CC) $(FLAGS) $(SRCS_CLIENT_BONUS) -o client_bonus
	@echo "Bonus is ready"

all: $(NAME)

bonus: $(NAME_BONUS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJC_c) $(OBJC_s) $(OBJC_C_B) $(OBJC_S_B)
	@echo "objects removed"
fclean:
	@rm  -f $(NAME) $(NAME_BONUS) $(OBJC_s) $(OBJC_c) $(OBJC_C_B) $(OBJC_S_B)
	@echo "objects and executable removed"
re:	clean all

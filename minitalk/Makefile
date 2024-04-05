CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJC_s = $(SRCS_SERVER:.c=.o)
OBJC_c = $(SRCS_CLIENT:.c=.o)
NAME = server client

$(NAME): $(OBJC_c) $(OBJC_s) $(SRCS_CLIENT) $(SRCS_SERVER)
	@$(CC) $(FLAGS)  $(SRCS_SERVER) -o server
	@$(CC) $(FLAGS) $(SRCS_CLIENT) -o client
	@echo "server and client are ready"

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJC_c) $(OBJC_s)
	@echo "objects removed"
fclean:
	@rm  -f $(NAME) $(OBJC_s) $(OBJC_c)
	@echo "objects and executable removed"
re:	clean all

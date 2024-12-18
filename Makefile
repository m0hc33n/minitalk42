CC = cc 
CFLAGS = -Wall -Wextra -Werror

CLIENT_HDR = inc/client.h 
SERVER_HDR = inc/server.h 
TOOLS_HDR  = inc/tools.h

SERVER_SRC = server-src/server.c
CLIENT_SRC = client-src/client.c client-src/arg_handler.c
TOOLS_SRC  = tools/pid_handler.c tools/helper.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
TOOLS_OBJ  = $(TOOLS_SRC:.c=.o)

SERVER_BONUS_SRC = server-src/server_bonus.c
CLIENT_BONUS_SRC = client-src/client_bonus.c client-src/arg_handler.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

CLIENT = client 
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all : $(CLIENT) $(SERVER)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER) : $(SERVER_OBJ) $(TOOLS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(TOOLS_OBJ) -o $@

$(CLIENT) : $(CLIENT_OBJ) $(TOOLS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(TOOLS_OBJ) -o $@

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJ) $(TOOLS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(TOOLS_OBJ) -o $@

$(SERVER_BONUS) : $(SERVER_BONUS_OBJ) $(TOOLS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(TOOLS_OBJ) -o $@

$(CLIENT_OBJ) : $(CLIENT_HDR) $(TOOLS_HDR)

$(SERVER_OBJ) : $(SERVER_HDR) $(TOOLS_HDR)

$(CLIENT_BONUS_OBJ) : $(CLIENT_HDR) $(TOOLS_HDR)

$(SERVER_BONUS_OBJ) : $(SERVER_HDR) $(TOOLS_HDR)

$(TOOLS_OBJ)  : $(TOOLS_HDR)

clean :
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(TOOLS_OBJ)
	rm -f $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)

fclean : clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS)  $(SERVER_BONUS)
re : fclean all 

.PHONY : clean
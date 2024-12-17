CC = cc 
CFLAGS = -Wall -Wextra -Werror
CLIENT_HDR = inc/client.h 
SERVER_HDR = inc/server.h 
TOOLS_HDR  = inc/tools.h
SERVER_SRC = server-src/server.c
CLIENT_SRC = client-src/client.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
TOOLS_SRC  = tools/pid_handler.c tools/helper.c
TOOLS_OBJ  = $(TOOLS_SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : server client

server : $(SERVER_OBJ) $(TOOLS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(TOOLS_OBJ) -o server

client : $(CLIENT_OBJ) $(TOOLS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(TOOLS_OBJ) -o client

$(CLIENT_OBJ) : $(CLIENT_HDR) $(TOOLS_HDR)

$(SERVER_OBJ) : $(SERVER_HDR) $(TOOLS_HDR)

$(TOOLS_OBJ)  : $(TOOLS_HDR)

clean :
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(TOOLS_OBJ)

fclean : clean
	rm -f client server

re : fclean all
CC = gcc
CFLAGS = -o mysyslog-client mysyslog-client.c -L. -lmysyslog

# Название клиента
CLIENT = mysyslog-client

all: $(CLIENT)

$(CLIENT): mysyslog-client.c
	$(CC) $(CFLAGS)

clean:
	rm -f $(CLIENT)

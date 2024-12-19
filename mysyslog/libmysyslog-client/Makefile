CC = gcc
CFLAGS = -c -fPIC  # -fPIC необходимо для создания динамической библиотеки
AR = ar
ARFLAGS = rcs
TARGET_STATIC = libmysyslog.a
TARGET_DYNAMIC = libmysyslog.so
SOURCES = /home/ubuntu/lab2/mysyslog/libmysyslog/libmysyslog.c
OBJECTS = $(SOURCES:.c=.o)

# Название клиента
CLIENT = mysyslog-client
CLIENT_SOURCES = mysyslog-client.c

all: $(TARGET_STATIC) $(TARGET_DYNAMIC) $(CLIENT)

# Правило для создания статической библиотеки
$(TARGET_STATIC): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

# Правило для создания динамической библиотеки
$(TARGET_DYNAMIC): $(OBJECTS)
	$(CC) -shared -o $@ $^

# Правило для компиляции .c в .o
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Правило для создания клиента
$(CLIENT): $(CLIENT_SOURCES) $(TARGET_STATIC) $(TARGET_DYNAMIC)
	$(CC) -o $@ $^ -L. -lmysyslog

clean:
	rm -f $(OBJECTS) $(TARGET_STATIC) $(TARGET_DYNAMIC) $(CLIENT)

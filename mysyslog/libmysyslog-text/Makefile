CC=gcc
CFLAGS=-fPIC -shared
TARGET=libmysyslog_text.so

all: $(TARGET)

$(TARGET): libmysyslog_text.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)

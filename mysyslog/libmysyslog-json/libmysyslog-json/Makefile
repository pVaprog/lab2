CC=gcc
CFLAGS=-fPIC -shared
TARGET=libmysyslog_json.so

all: $(TARGET)

$(TARGET): libmysyslog_json.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(TARGET)

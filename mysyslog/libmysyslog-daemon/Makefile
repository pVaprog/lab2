CC = gcc
CFLAGS = -Wall
TARGET = mysyslog-daemon
SOURCES = mysyslog-daemon.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean deb

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJECTS) $(TARGET)

deb: 
	mkdir -p ../debian/mysyslog-daemon
	cp -r debian/* ../debian/mysyslog-daemon/
	dpkg-deb --build ../debian/mysyslog-daemon
	rm -rf ../debian/mysyslog-daemon


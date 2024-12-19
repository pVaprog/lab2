CC = gcc
CFLAGS = -c -fPIC  # -fPIC необходимо для создания динамической библиотеки
AR = ar
ARFLAGS = rcs
TARGET_STATIC = libmysyslog.a
TARGET_DYNAMIC = libmysyslog.so
SOURCES = libmysyslog.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET_STATIC) $(TARGET_DYNAMIC)

# Правило для создания статической библиотеки
$(TARGET_STATIC): $(OBJECTS)
	 $(AR) $(ARFLAGS) $@ $^

# Правило для создания динамической библиотеки
$(TARGET_DYNAMIC): $(OBJECTS)
	 $(CC) -shared -o $@ $^

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET_STATIC) $(TARGET_DYNAMIC)

deb: 
	mkdir -p ../debian/mysyslog-lib
	cp -r debian/* ../debian/mysyslog-lib/
	dpkg-deb --build ../debian/mysyslog-lib
	rm -rf ../debian/mysyslog-lib

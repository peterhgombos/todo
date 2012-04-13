CC=gcc
CFLAGS=-c -g -Wall -O2 -mtune=native
LDFLAGS=
SOURCES=todo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=todo
PREFIX=/usr/local

all: $(SOURCES) $(EXECUTABLE) 
	@touch todofile

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf *.o $(EXECUTABLE)

install: $(EXECUTABLE)
	@install -m 0755 $(EXECUTABLE) $(PREFIX)/bin

uninstall:
	@rm $(PREFIX)/bin/$(EXECUTABLE)

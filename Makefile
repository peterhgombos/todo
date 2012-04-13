CC=gcc
CFLAGS=-c -g -Wall -O2 -mtune=native
LDFLAGS=
SOURCES=todo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=todo

all: $(SOURCES) $(EXECUTABLE) 
	touch todofile

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

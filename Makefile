CC = gcc
CFLAGS = -g -Wall
HEADERS = utils.h wrap.h align_left.h align_right.h center.h paragraph.h \
	  justify.h list.h ordered_list.h syntax_checker.h parser.h
OBJECTS = utils.o wrap.o align_left.o align_right.o center.o paragraph.o \
	  justify.o list.o ordered_list.o syntax_checker.o parser.o main.o
EXEC = format_text

.PHONY = default build clean

default: build

build: format_text

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -lm

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ -lm

run: build
	./$(EXEC) ${ARGS}

clean:
	-rm -f $(OBJECTS)
	-rm -f $(EXEC)

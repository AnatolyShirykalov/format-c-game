
SOURCES=linux.c \
	units.c \
	fight.c \
	grammar.c messages.c \
	rooms/default.c

OBJDIR=OBJECTS

PROG_NAME=linux

CFLAGS=-O3 -g -lm

all: $(PROG_NAME)


include rules.mk

$(PROG_NAME): $(OBJS)
	$(CC)  -s -o $@ $+ $(CFLAGS)


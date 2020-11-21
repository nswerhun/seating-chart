CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic-errors -std=c99
OUTFILE = seating-chart
OBJS = main.c

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJS)

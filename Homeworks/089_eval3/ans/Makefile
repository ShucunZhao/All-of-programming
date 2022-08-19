OBJS=cyoa-step2.o book.o page.o
CC=g++
CFLAGS=-std=gnu++11 -pedantic -Wall -Werror -ggdb3

cyoa-step2: $(OBJS)
	$(CC) $^ $(CFLAGS) -o cyoa-step2

%.o:%.cpp
	$(CC) $^ -c $(CFLAGS) -o $@

.PHONY: clean
clean:
	$(RM) *.o cyoa-step2 -r

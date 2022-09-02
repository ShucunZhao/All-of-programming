OBJS=cyoa-step3.o book.o page.o
CC=g++
CFLAGS=-std=gnu++11 -pedantic -Wall -Werror -ggdb3

cyoa-step3: $(OBJS)
	$(CC) $^ $(CFLAGS) -o cyoa-step3

%.o:%.cpp
	$(CC) $^ -c $(CFLAGS) -o $@

.PHONY: clean
clean:
	$(RM) *.o cyoa-step3 -r

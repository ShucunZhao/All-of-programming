CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
OBJS=counts.o counts_test.o
PROGRAM=counts_test

$(PROGRAM): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

%.o: %.c 
	gcc -c $(CFLAGS) $<

clean:
	rm -rf $(OBJS) $(PROGRAM) *~ 

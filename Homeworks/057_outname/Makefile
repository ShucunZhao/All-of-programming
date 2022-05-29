CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
OBJS=outname.o outname_test.o
PROGRAM=outname_test

$(PROGRAM): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

%.o: %.c 
	gcc -c $(CFLAGS) $<

clean:
	rm -rf $(OBJS) $(PROGRAM) *~ 

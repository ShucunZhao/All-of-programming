CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
OBJS=kv.o outname.o counts.o
PROGRAM=hw059

$(PROGRAM): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS) main.c

%.o: %.c 
	gcc -c $(CFLAGS) $<

clean:
	rm -rf $(OBJS) $(PROGRAM) *~ 

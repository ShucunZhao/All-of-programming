CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
OBJS=provided.o rand_story.o
PROGRAM=rand_story

$(PROGRAM): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

%.o: %.c 
	gcc -c $(CFLAGS) $<

clean:
	rm -rf $(OBJS) $(PROGRAM) *~ 

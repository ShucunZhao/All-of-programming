CFLAGS=-Wall -Werror -std=gnu99 -pedantic -ggdb3
OBJS=provided.o rand_story.o story-step1.o
PROGRAM=story-step1

$(PROGRAM): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

%.o: %.c 
	gcc -c $(CFLAGS) $<

clean:
	rm -rf $(OBJS) $(PROGRAM) *~ 

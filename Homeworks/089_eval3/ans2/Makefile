CFLAGS=--std=gnu++11 -pedantic -Wall -Werror -ggdb3
PROGS=cyoa-step1 cyoa-step2 cyoa-step3
OBJS=cyoa.o cyoa-step1.o cyoa-step2.o cyoa-step3.o
all: $(PROGS)
cyoa-step%: cyoa-step%.o cyoa.o
	g++ $^ $(CFLAGS) -o $@
%.o: %.cpp
	g++ $(CFLAGS) -c $<
.PHONY: clean
clean:
	rm -f *~ $(PROGS) $(OBJS)
cyoa.o: cyoa.h

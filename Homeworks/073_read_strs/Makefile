CPPFLAGS=-std=gnu++11 -pedantic -Wall -Werror -ggdb3
test: test.o
	g++ -o test test.o
test.o: test.cpp
	g++ $(CPPFLAGS) -c test.cpp

.PHONY: clean
clean:
	rm -f *.o *~ test

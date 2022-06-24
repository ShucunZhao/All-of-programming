CPPFLAGS=-std=gnu++98 -pedantic -Wall -Werror -ggdb3
main: vector.o
	g++ -o main main.cpp vector.o
vector.o: vector.cpp vector.hpp
	g++ $(CPPFLAGS) -c vector.cpp

.PHONY: clean
clean:
	rm -f *.o *~ main

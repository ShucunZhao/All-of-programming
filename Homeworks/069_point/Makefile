CPPFLAGS=-std=gnu++98 -pedantic -Wall -Werror -ggdb3
main: main.cpp point.o
	g++ $(CPPFLAGS) -o main main.cpp point.o
point.o: point.cpp point.hpp
	g++ $(CPPFLAGS) -c point.cpp

.PHONY: clean
clean:
	rm -f *.o *~ main

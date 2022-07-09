CPPFLAGS=-std=gnu++11 -pedantic -Wall -Werror -ggdb3
Q16.4: Q16.4.o
	g++ -o Q16.4 Q16.4.o
Q16.4.o: Q16.4.cpp Q16.4.hpp
	g++ $(CPPFLAGS) -c Q16.4.cpp Q16.4.hpp
#vector.o: vector.cpp vector.hpp
#	g++ $(CPPFLAGS) -c vector.cpp

.PHONY: clean
clean:
	rm -f *.o *~ Q16.4

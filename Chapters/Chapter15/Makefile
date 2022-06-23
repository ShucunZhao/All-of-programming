CPPFLAGS=-std=gnu++98 -pedantic -Wall -Werror -ggdb3
Q15.10: Q15.10.o
	g++ -o Q15.10 Q15.10.o
Q15.10.o: Q15.10.cpp Q15.10.hpp
	g++ $(CPPFLAGS) -c Q15.10.cpp
#vector.o: vector.cpp vector.hpp
#	g++ $(CPPFLAGS) -c vector.cpp

.PHONY: clean
clean:
	rm -f *.o *~ Q15.10

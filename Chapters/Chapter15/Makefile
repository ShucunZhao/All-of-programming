CPPFLAGS=-std=gnu++98 -pedantic -Wall -Werror -ggdb3
Q15.9: Q15.9.o
	g++ -o Q15.9 Q15.9.o
Q15.9.o: Q15.9.cpp Q15.9.hpp
	g++ $(CPPFLAGS) -c Q15.9.cpp
#vector.o: vector.cpp vector.hpp
#	g++ $(CPPFLAGS) -c vector.cpp

.PHONY: clean
clean:
	rm -f *.o *~ Q15.9

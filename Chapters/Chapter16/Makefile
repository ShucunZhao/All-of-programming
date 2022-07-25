CPPFLAGS=-std=gnu++11 -pedantic -Wall -Werror -ggdb3
fileSum2: fileSum2.o
	g++ -o fileSum2 fileSum2.o
fileSum2.o: fileSum2.cpp
	g++ $(CPPFLAGS) -c fileSum2.cpp
#myCat2: myCat2.o
#	g++ -o myCat2 myCat2.o
myCat2.o: myCat2.cpp
#	g++ $(CPPFLAGS) -c myCat.cpp
#myEcho: myEcho.o
#	g++ -o myEcho myEcho.o
#myEcho.o: myEcho.cpp
#	g++ $(CPPFLAGS) -c myEcho.cpp
#Q16.5: Q16.5.o
#	g++ -o Q16.5 Q16.5.o
#Q16.5.o: Q16.5.cpp Q16.5.hpp
#	g++ $(CPPFLAGS) -c Q16.5.cpp Q16.5.hpp
#Q16.4: Q16.4.o
#	g++ -o Q16.4 Q16.4.o
#Q16.4.o: Q16.4.cpp Q16.4.hpp
#	g++ $(CPPFLAGS) -c Q16.4.cpp Q16.4.hpp
#vector.o: vector.cpp vector.hpp
#	g++ $(CPPFLAGS) -c vector.cpp

.PHONY: clean
clean:
#	rm -f *.o *~ fileSum
	rm -f *.o *~ myCat2
#	rm -f *.o *~ myEcho
#	rm -f *.o *~ Q16.5
#	rm -f *.o *~ Q16.4

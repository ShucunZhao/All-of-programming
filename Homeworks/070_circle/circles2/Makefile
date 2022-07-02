CPPFLAGS=-Wall -Werror -std=gnu++11 -pedantic -ggdb3
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp, %.o, $(SRCS))
PROGRAM=circles2

$(PROGRAM): $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS)

%.o: %.cpp point2.hpp circle2.hpp
	g++ -c $(CPPFLAGS) $<

clean:
	rm -f $(OBJS) $(PROGRAM) *~

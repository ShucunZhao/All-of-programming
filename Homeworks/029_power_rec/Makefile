CC= gcc
CFLAGS = -Wall -Werror -pedantic -std=gnu99 -ggdb3 -O3
test-power: power.o test-power.o
	$(CC) -o test-power power.o test-power.o
power.o: power.c
	$(CC) $(CFLAGS) -c power.c
test-power.o: test-power.c
	$(CC) $(CFLAGS) -c test-power.c

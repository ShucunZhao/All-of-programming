CC=gcc 
CFLAGS =-Wall -Werror -pedantic -std=gnu99 -ggdb3 -O3
checkClosest: computeDist.o closestPoint.o checkClosest.c
	$(CC) -o checkClosest computeDist.o closestPoint.o checkClosest.c -lm
computeDist.o: computeDist.c
	$(CC) $(CFLAGS) -c computeDist.c
closestPoint.o: closestPoint.c
	$(CC) $(CFLAGS) -c closestPoint.c

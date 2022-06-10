#include <cstdio>
#include <cstdlib>

void f(int & y, int * z){
	printf("y = %d, *z = %d\n", y, *z);
	y+=*z;//b=b*z=4*4=14
	*z=42;//a,x=42
}

int main(void){
	int a=3;
	int b=4;
	int & x = a;
	x = b;
	printf("a = %d, b = %d, x = %d\n", a, b, x);
	f(b, &x);
	printf("a = %d, b = %d, x = %d\n", a, b, x);
	return EXIT_SUCCESS;
}
/*Output:
 *1. a = 4, b = 4, x = 4
 *2. y = 4, *z = 4
 *3. a = 42, b = 14, x = 42
 */

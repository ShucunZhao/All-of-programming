#include <stdio.h>

int main(){
	int a =6;
	char b = a + '0';
	char c = (char)a;
	printf("a -c:%c\n", a);
	printf("a -d:%d\n", a);
	printf("a-'0' -c:%c\n", b);
	printf("(char)a -c:%c\n",c);
	printf("a-'0' - d:%d\n", b);
	printf("(char)a -d:%d\n",c);
	return 0;
}

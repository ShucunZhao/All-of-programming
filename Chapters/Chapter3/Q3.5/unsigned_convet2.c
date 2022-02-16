#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char str_bin[32];
    gets(str_bin);
    int sizeBin = strlen(str_bin);
    int sum = 0;
    for(int i = 0; i < sizeBin; i ++)
        sum += (int)pow(2,(sizeBin-1-i)) * (str_bin[i] - '0');
    printf("%d",sum);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXRANGE 256

int main()
{
    char binaryScanf[MAXRANGE]; // 有符号字符二进制
    int decimal = 0;   // 所求十进制

    scanf("%s", binaryScanf);   // 输入二进制数

    if(binaryScanf[0] == '1')   // 符号位 == 1
    {
    	// 逆补码
        for(int i = strlen(binaryScanf) - 1; i > 0; i --)
        {
            binaryScanf[i] -= 1;
            if(binaryScanf[i] == '0')
                break;
            else
                binaryScanf[i] = '1';
        }
        // 逆反码
        for(int i = strlen(binaryScanf) - 1; i > 0; i --)
            binaryScanf[i] == '0' ? (binaryScanf[i] = '1') : (binaryScanf[i] = '0');
        // 二转十公式
        for(int j = 0, i = strlen(binaryScanf) - 1; i > 0; i --)
            decimal += (binaryScanf[i] - '0') * (int)pow(2,j++);
        decimal = 0 - decimal;  // 取负
    }
    else    // 符号位 == 0
        for(int j = 0, i = strlen(binaryScanf) - 1; i > 0; i --)
            decimal += (binaryScanf[i] - '0') * (int)pow(2,j++);
    printf("%d\n",decimal);
    return 0;
}


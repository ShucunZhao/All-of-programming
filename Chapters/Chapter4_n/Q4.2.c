#include<stdio.h>
#include<math.h>

float avg3(int a, int b, int c){
    
    float ans = (a+b+c)/(float)3;
    return ans;

}

int main(){
    int a,b,c;
    printf("Please enter three integers:\n");
    scanf("%d, %d, %d", &a, &b, &c);
    printf("The average of '%d','%d', '%d' is :\n %f", a, b, c, avg3(a,b,c));
    return 0;
}

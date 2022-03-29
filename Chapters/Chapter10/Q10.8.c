#include <stdio.h>

void addMatricies(double ** ans, double ** a, double ** b, int w, int h){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			ans[i][j]=a[i][j]+b[i][j]; 
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			printf("Result:%lf\n", ans[i][j]);
		}
	}
}

int main(){
	int w=4;
	int h=3;
	double a0[4] = {15.0,10.0,9.0,12.0};
	double a1[4] = {18.0,14.0,8.0,7.0};
	double a2[4] = {16.0,13.0,6.0,11.0};
	double * A[3] = {a0,a1,a2};
	double b0[4] = {4.0,3.0,5.0,2.0};
	double b1[4] = {0.0,9.0,6.0,1.0};
	double b2[4] = {5.0,7.0,2.0,6.0};
	double * B[3] = {b0,b1,b2};
	double c0[4];
	double c1[4];
	double c2[4];
	double * ans[3]={c0,c1,c2};
	addMatricies(ans,A,B,w,h);
	return 0;
}

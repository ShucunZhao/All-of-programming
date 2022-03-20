#include <stdio.h>

int maxSeq(int *array, int *save, size_t n){
	if(n==0){
		return 0;
	}
	_Bool flag;
	int j=0;
	int counter = 1;
	for(int x=0;x<n;x++){
		int *larger = &array[x];
		for(int i=x+1;i<n;i++){
			if(array[i]>*larger){
				counter++;
				larger = &array[i];
				flag = 1;
			}
			else{
				flag = 0;
				save[j] = counter;
	 			counter = 1;
				j++;
				break;
			}
		}
		if(flag){
			save[j+1] = counter;
			j++;
			counter = 1;
		}
	}
	int *largest = &save[0];
	for(int i=1; i<n; i++){
		if(save[i]>*largest){
			largest = &save[i];
		}
	}
	return *largest;
}

int main(){
	int i_set[] = {-1,-5,-6,-4,-3,2,9,0};
	int save[sizeof(i_set)/sizeof(i_set[0])]={0};
	//int test[]={1,2,3,4};
	//printf("size:%ld\n", sizeof(test)/sizeof(test[0]));
	printf("The length of maximum increasing contiguous subsequence is: %d\n", maxSeq(i_set, save, sizeof(i_set)/sizeof(i_set[0])));
	return 0;
}

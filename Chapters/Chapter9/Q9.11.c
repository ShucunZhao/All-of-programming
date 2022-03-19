#include <stdio.h>

int *maxElement(int *result, size_t n){
	int *largest = &result[0];
	for(int i=1; i<n; i++){
		if(result[i]>*largest){
			largest = &result[i];
		} 
	}
	return largest;
}

int *maxSeq(int *array, int *save, size_t n){
	_Bool flag;
	int j=0;
	int counter = 1;
	for(int x=0;x<n;x++){
		int *larger = &array[x];
 	//	int counter = 0;
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
	return maxElement(save, n);
	//return save;
}

int main(){
	int save[50] = {0};
	//int i_set[10] = {1,2,1,3,6,7,2,4,6,9};
	int i_set[10] = {2,2,3,4,5,6,7,8,9,10};
	int *p = maxSeq(i_set,save, 10);
//	for(int i=0;i<14;i++){
//		printf("%d\n", *p);
//		p++;
//	}
	printf("The length of maximum increasing contiguous subsequence is: %d\n", *p);
	return 0;
}

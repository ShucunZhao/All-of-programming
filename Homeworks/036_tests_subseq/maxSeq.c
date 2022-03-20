#include <stdio.h>

size_t maxSeq(int *array, size_t n){
	if(n==0){
		return 0;
	}
	int counter = 1;
	size_t maxCounter = counter;
	int larger = array[0];
	for(int i=1;i<n;i++){
		if(array[i]>larger){
			counter++;
			}
		else{
	 		counter = 1;					}
		if(counter>maxCounter){
			maxCounter = counter;
		}
	}
	return maxCounter;
}

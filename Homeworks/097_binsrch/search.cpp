#include "function.h"

int binarySearchZero(Function<int, int> * f, int low, int high){
	int mid;
	int rst;
	while(low<=high-1){
		mid = low+(high-low)/2;
		rst = f->invoke(mid);
		if(rst>0){
			high = mid-1;
		}
		else if(rst<0){
			low = mid+1;
		}
		else{
			return mid;
		}
	}
	return low;
}

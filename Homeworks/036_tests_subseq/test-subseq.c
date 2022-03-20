#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);

void testSubseq(size_t result, size_t ans){
	if(result!=ans){
		exit(EXIT_FAILURE);
	//	printf("failure.\n");
	}
}

int main(){
	int array1[]={1,2,1,3,5,7,2,4,6,9};
	testSubseq(maxSeq(array1,sizeof(array1)/sizeof(array1[0])),4);
	int array2[]={2,2,2,2,2,5};
	testSubseq(maxSeq(array2,sizeof(array2)/sizeof(array2[0])),2);
	int array3[]={5,4,3,2,1,0};
	testSubseq(maxSeq(array3,sizeof(array3)/sizeof(array3[0])),1);
	int array4[]={-1,0,2,2,2,5};
	testSubseq(maxSeq(array4,sizeof(array4)/sizeof(array4[0])),3);
	int array5[1]={0};
	testSubseq(maxSeq(array5,0),0);
 	return EXIT_SUCCESS;
}

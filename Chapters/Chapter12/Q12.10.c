#include <stdio.h>
#include <stdlib.h>

typedef struct my_struct_tag{
	size_t nNums;
	int * nums;
} my_struct;

void f(my_struct * ptr){
	for(int i=0;i<ptr->nNums;i++){//nNums only has totally 5, cannot printf
		//6 times.
		printf("%d\n", ptr->nums[i]);
	}
	//free(ptr);//The first one?
}

int main(){
	my_struct * s = malloc(5 * sizeof(*s));//2nd?
	s->nNums = 5;
	s->nums = malloc(5*sizeof(*s->nums));//3rd?
	for(int i=0;i<s->nNums;i++){
		s->nums[i] = i+4;
	}
	f(s);
	free(s->nums);
	free(s);
	//free(s);
	return EXIT_SUCCESS;
}

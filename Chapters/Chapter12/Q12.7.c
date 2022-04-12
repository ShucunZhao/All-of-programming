#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * myStrdup(const char * str){
	size_t len = strlen(str)+1;//Because the strlen is end with terminate '\0'(not include), so we should plus one for filling the terminate.
	char * dup = malloc(len*sizeof(*dup));
	strncpy(dup, str, len);//If the str length is small than dup, the rest part would be filled with '\0'(NULL).
	return dup;
}

int main(int argc, char ** argv){
	char test[]="Test case.";
	/*for(int i=0;i<strlen(test);i++){
		printf("test[%d]:%c\n", i, test[i]);
	}*/
	char * ans = myStrdup(test);
	/*for(int j=0;j<strlen(ans);j++){
		printf("Ans[%d]:%c\n", j, ans[j]);
	}*/
	printf("Ans:%s\n", ans);
	free(ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpStr(const void * s1, const void * s2){
	char * const * s1ptr = s1;
	char * const * s2ptr = s2;
	return strcmp(*s1ptr, *s2ptr);
}

void sort(char ** lines, size_t n){
	qsort(lines, n, sizeof(*lines), cmpStr);
}

int main(int argc, char ** argv){
	if(argc<2){
		fprintf(stderr, "You should enter command line argument!\n");
		return EXIT_FAILURE;
	}
	char ** lines = NULL;
	char * cur = NULL;
	size_t linecap;
	size_t i = 0;
	for(int j=1;j<argc;j++){
		FILE * f = fopen(argv[j], "r");
		if(f==NULL){
			fprintf(stderr, "The file %s is invalid!\n", argv[j]);
			return EXIT_FAILURE;
		}
		while(getline(&cur,&linecap,f)>=0){
			lines = realloc(lines, (i+1)*sizeof(*lines));
			lines[i] = cur;
			cur = NULL;
			i++;
		}
		if(fclose(f)!=0){
			fprintf(stderr, "The file %s failed to close!\n", argv[i]);
			return EXIT_FAILURE;
		}
	}
	free(cur);
	sort(lines, i);
	for(size_t k=0;k<i;k++){
		printf("%s", lines[k]);
		free(lines[k]);
	}
	free(lines);
	return EXIT_SUCCESS;
}

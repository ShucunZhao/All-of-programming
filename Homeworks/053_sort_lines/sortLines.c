#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void printData(char ** data, size_t count){
	for(size_t i=0;i<count;i++){
		fprintf(stdout, "%s", data[i]);
		//printf("%s", data[i]);
		free(data[i]);
	}
	free(data);
}

int main(int argc, char ** argv){
	char ** lines = NULL;
	char * cur = NULL;
	size_t linecap;
	size_t n=0;
	if(argc>1){
		for(int i=1;i<argc;i++){
			FILE * f = fopen(argv[i], "r");
			if(f==NULL){
				fprintf(stderr, "Failed to open %s\n", argv[i]);
				return EXIT_FAILURE;
			}
			while(getline(&cur, &linecap, f)>=0){
				lines = (char**)realloc(lines, (n+1)*sizeof(char*));
				lines[n] = cur;
				cur = NULL;
				n++;
			}
			if(fclose(f)!=0){
				fprintf(stderr, "Failed to close %s\n", argv[i]);
				return EXIT_FAILURE;
			}
		}
		free(cur);
		sortData(lines, n);
		printData(lines, n);
	}
	else{
		//char c = getchar();
		while(getline(&cur, &linecap, stdin)!=EOF){
			lines = (char**)realloc(lines, (n+1)*sizeof(char*));
			lines[n] = cur;
			cur = NULL;
			n++;
		}
		printf("You enter 'Ctrl+D'(EOF of linux) to end the input, the sorting result is:\n");
		free(cur);
		sortData(lines, n);
		printData(lines, n);
	}
	return EXIT_SUCCESS;
}

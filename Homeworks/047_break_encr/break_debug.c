#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*Maybe:
* U can guess: the highest frequency occur alphabet in input with the distribution of letters in alphabet using frequency.
*/
char sortAlpha(char * f){
	int i=0;
	char save[1024]={'\0'};
	while(*f!='\0'){
		char c = *f;
		if(isalpha(c)){
			save[i]=c;
			i++;
		}
		f++;
	}
	int count[26]={0};
	for(int j=0;save[j]!='\0';j++){
		count[save[j]-'a']+=1;
	}
	int index=0;
	int curMax = count[index];
	for(int k=0;k<26;k++){
		if(count[k]>curMax){
			curMax = count[k];
			index=k;
		}
	}
	char Most = index + 'a';
	printf("The most frequency alpha is:%c\n", Most);
	return Most;
}

int getKey(char Most){
	int key = 0;
	//((('e'-'a')+key)%26)+'a'=Most;
	//Anscii: 'e'=101, 'a'=97
	//((4+key)%26)=Most-97;
	while(((key+4)%26)!=(Most - 'a')){
		key++;
	}
	printf("The key is:%d\n", key);
	return key;
}

void breakEncrypt(char * f, int key){
	int x;//start from 'a'
	printf("The break result is:\n");
	while(*f!='\0'){
		char c = *f;
		if(isalpha(c)){
			x='a';
			while(((x-'a')+key)%26!=(c-'a')){
				x++;
			}
			printf("%c", x);
		}
		else{
			printf("%c", *f);
		}
		f++;
	}
	printf("\n");
}

int main(int argc, char ** argv){
	/*if(argc!=2){
		fprintf(stderr, "Please enter one argument!\n");
		return EXIT_FAILURE;
	}
	FILE * f = fopen(argv[1], "r");
	if(f==NULL){
		fprintf(stderr, "The file %s cannot be opened!\n", argv[1]);
		return EXIT_FAILURE;
	}*/
	char f[25] = "fs jcfruqj\ntk ymj nsuzy.\0";
	printf("The input is:\n");
	for(int i=0;i<25;i++){
		printf("%c", f[i]);
	}
	printf("\n");
	char Most = sortAlpha(f);
	int key = getKey(Most);
	breakEncrypt(f, key);

	return EXIT_SUCCESS;
}

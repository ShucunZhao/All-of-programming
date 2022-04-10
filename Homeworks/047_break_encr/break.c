/*Maybe:
* U can guess the highest frequency occur alphabet in input with the distribution
* of letters in alphabet using frequency.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * This function is to sort the input file and get the most frequency alphabet.
 * @param f - Input file stream
 * @return - An char occur the most time
 */
char sortAlpha(FILE * f){

	//Step1: Save all alpha into a string:
	int c;
	int i=0;
	char save[1024]={'\0'};//Store all the alpha in input file for next counting step.
	while((c=fgetc(f))!=EOF){
		if(isalpha(c)){
			save[i]=c;
			i++;
		}
	}

	//Step2:Find the most frequency element:
	int count[26]={0};//Small alpha has 26 characters so set an int array to represent the occur time of them.
	//Step2.1: Count each element occur times:
	for(int j=0;save[j]!='\0';j++){
		//printf("save[j]:%c\n",save[j]);
		count[save[j]-'a']+=1;//If one of which occur, change their counter to add 1.
	}
	//Step2.2:Find the most frequency one's index:
	int index=0;
	int curMax = count[index];
	for(int k=0;k<26;k++){
		if(count[k]>curMax){
			curMax = count[k];
			index = k;
		}
	}

	//Step3:transform the index into an alpha char:
	char Most = index + 'a';
	printf("The most frequency alpha is:%c\n", Most);
	return Most;
}

/*
 * Get key function: Assume the origin text of the most frequency input alpha is 'e'
 * (The most frequency is 'e' in text) to decode the encrypt process to get the key. 
 * @param Most - Most frequency alpha of input
 * @return - Key for breaking step
 */
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

/*
 * Decode the encrpt process with key.
 * @param f - Input file stream
 * @param key - key we got form last step
 */
void breakEncrypt(FILE * f, int key){
	int c;
	int x;
	printf("The break result is:\n");
	while((c=fgetc(f))!=EOF){
		if(isalpha(c)){
			x='a';//start from 'a'(represent 97 when int type.)
			while(((x-'a')+key)%26!=(c-'a')){
				x++;
			}
			printf("%c", x);
		}
		else{
			printf("%c", c);
		}
	}
	printf("\n");
}

int main(int argc, char ** argv){
	if(argc!=2){
		fprintf(stderr, "Please enter one argument!\n");
		return EXIT_FAILURE;
	}
	FILE * f1 = fopen(argv[1], "r");
	//FILE * f2 = fopen(argv[1], "r");
	if(f1==NULL){
		fprintf(stderr, "The file %s cannot be opened!\n", argv[1]);
		return EXIT_FAILURE;
	}
	//FILE * head = f1;
	//printf("head1:%s\n", head);
	char Most = sortAlpha(f1);
 	//if(fclose(f1)!= 0){
   // 	perror("Failed to close the input file!\n");
    //	exit(EXIT_FAILURE);
	//}
	//printf("f1:%s\n",f1);
	rewind(f1);//This function can repoint the FILE stream to the head.
	int key = getKey(Most);	
	breakEncrypt(f1, key);
 	if(fclose(f1)!= 0){
    	perror("Failed to close the input file!\n");
    	exit(EXIT_FAILURE);
    }

	return EXIT_SUCCESS;
}

#include <stdio.h>
//A hexadecimal number is always positive.
int mytoiHex(const char * str){
	int n = 6;
	int filter[6]={-1,-1,-1,-1,-1,-1};
	while(*str==' '){
		str++;
	}
	if(*str<'0'||(*str>'9'&&*str<'A')||(*str-'A')>5){
		return 0;
	}
	//int binary=0;
	int decimal=0;
	int k=1;
	int i;
	while(((*str-'A')<=5&&*str!='\0')||(*str>='0'&&*str<='9'&&*str!='\0')){
		//int k=1;
		//binary*=10000;
		//decimal=decimal+decimal*16*i
		n--;
		if(*str>='0'&&*str<='9'){
			i = *str-'0';
			filter[n]=i;
			//decimal = decimal+deciaml*k*i;
			//k*=16;
			//while((i/2)!=0){
			//	binary = binary + k*(i%2);
			//	i/=2;
			//	k*=10;
			//}
			//binary = binary + k*(i%2);
			str++;
			continue;
		}
		if((*str-'A')<=5){
			if(*str==' '){
				str++;
				continue;
			}
			i = *str-'A'+10;
			filter[n]=i;
			//decimal=decimal+deciaml*k+i
			//k*=16;
			//while((i/2)!=0){
			//	binary = binary + k*(i%2);
			//	i/=2;
			//	k*=10;
			//}
			//binary = binary + k*(i%2);
			str++;
			continue;
		}
	}
	for(int j=0;j<6;j++){
		if(filter[j]==-1){
			continue;
		}
		//printf("Converted is:%d\n", filter[j]);
		decimal = decimal+k*filter[j];
		k*=16;
	}
	//printf("Filter form: %d\n", binary);
	return decimal; 
}

int main(){
	const char str[]="  C6\0D2";
	//const char str[]="  9";
	printf("%d\n",mytoiHex(str));
	//printf("%d", mytoiHex(str,strlen(str)));
	return 0;
}

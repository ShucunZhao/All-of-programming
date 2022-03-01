/*
 This file is the answer of Q5.4
*/
#include<stdio.h>

bool isPow2(int n){
	if(n==0){
	    return 0;
	}
	else{
	    if((n&(n-1))==0){
 	        return 1;
	    }
	    else{
			return 0;
	    }
	} 
}

int main(){
    for(int i=0; i<=20000000;i++){
	if(isPow2(i)){
	 printf("%d\n", i);   
	}
    }
    return 0;
}

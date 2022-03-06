//#include<stdio.h>

int max(int x, int y){
	if(x>=y){
		return x;
	}
	else{
		return y;
	}
}

_Bool between(int n, int low, int up){
	if(n>=low && n<up){
		return 1;
	}
	else{
		return 0;
	}
}

_Bool ifEqual(int n, int offset, int size2){
	if(n==offset||(n==offset+size2-1)){
		return 1;
	}
	else{
		return 0;
	}
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
	int w = max(size1, (x_offset+size2));
   //compute the max of size1 and (y_offset + size2).  Call this h
    int h = max(size1, (y_offset+size2));
	//count from 0 to h. Call the number you count with y
	for(int y=0; y<h; y++){
		//count from 0 to w. Call the number you count with x
		for(int x=0; x<w; x++){
      	//check if  EITHER
      	//    ((x is between x_offset  and x_offset +size2) AND
      	//     y is equal to either y_offset OR y_offset + size2 - 1 )
      	//  OR
      	//    ((y is between y_offset and y_offset + size2) AND
      	//     x is equal to either x_offset OR x_offset + size2 -1)
	  	if((between(x,x_offset,x_offset+size2)&&ifEqual(y,y_offset,size2))||(between(y,y_offset,y_offset+size2)&&ifEqual(x,x_offset,size2))){
      	  // if so, print a *
	 	 printf("*");
	  	}
     	else if(((x < size1)&&((y == 0)||(y == size1 - 1)))||((y < size1)&&((x == 0)||(x == size1 -1)))){
			//if so, print a #
			printf("#");
		}
        else{ //else print a space
			printf(" ");
		}
	  }
     //when you finish counting x from 0 to w,
      //print a newline
	  printf("\n");
  }
}

//int main(){
//	squares(6,3,4,7);
//	return 0;
//}

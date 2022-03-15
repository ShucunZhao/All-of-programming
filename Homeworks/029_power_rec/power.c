unsigned power(unsigned x, unsigned y, int acc){
	if(x==0){//while 0 to the 0 is undefined, we specify the result should be 1 for this function.
		return acc;
	}
	else if(y==0){
		return acc;
	}
	else{
		return power(x,y-1,acc*x);
	}
}

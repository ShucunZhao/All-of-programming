int BSTtoFind(int toFind, int * array, size_t n){
	size_t l=0,r=n;
	size_t m;
	while(l<r){
		m = l+(r-l)/2;
		if(array[m]>toFind){
			r = m;
		}
		else if(array[m]<toFind){
			l = l+1;
		}
		else{
			return m;
		}
	}
	return -1;
}

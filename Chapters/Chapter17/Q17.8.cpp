template<typename T>
int countEven(typename T::const_iterator start, typename T::const_iterator end){
	int count=0;
	while(start!=end){
		if(*start%2==0){
			count++;
		}
		++start;
	}
	return count;
}

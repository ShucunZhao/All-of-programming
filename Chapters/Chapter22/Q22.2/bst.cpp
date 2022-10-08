template<typename T, typename Container>
typename Container::const_iterator binarySearch(const T & toFind, typename Container::const_iterator start, typename Container::const_iterator end){
	typename Container::const_iterator notFind = end; 
	while(start<end){
		typename Container::const_iterator mid = start+(end-strat)/2;
		const T & cur = *mid; 
		if(cur > toFind){
			end = mid;
		}
		else if(cur < toFind){
			start = mid + 1;
		}
		else{
			return mid;
		}
	}
	return notFind;//
}

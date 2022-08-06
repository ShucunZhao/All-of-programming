template<typename T>
vector<pair<T1, T2> > flipPairs(const vector<pair<T1, T2> > & v){
	T * temp;
	temp = v.second;
	v.second = v.first;
	v.first = temp;
	std::swap(v);
	return v;
}

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<typename T>
void printElements(T & container){
	typename T::iterator it = container.begin();
	while(it!=container.end()){
		cout<<*it<<endl;
		++it;
	}
}

class OrderIgnoreCase{
public:
	bool operator()(const string & s1, const string & s2){
		for(size_t i=0;i<s1.size()&&i<s2.size();i++){
		char c1 = tolower(s1[i]);
		char c2 = tolower(s2[i]);
		if(c1!=c2){
			return c1<c2;
		}
		}
		return s1.size()<s2.size();
	}
};

int main(int argc, char ** argv){
	if(argc==1){
		vector<string> stdIn;
		string str;	
		while(getline(cin, str)){
			stdIn.push_back(str);
		}
		//sort(stdIn.begin(),stdIn.end());
		sort(stdIn.begin(),stdIn.end(),OrderIgnoreCase());
		printElements<vector<string> >(stdIn);//KeyPoint: the vector<string> is the real parameter of printElements function, it cannot omit generally.
		/*
		for(vector<string>::iterator it = stdIn.begin();it!=stdIn.end();++it){
		cout<<*it<<endl;
		}
		*/
	}
	else{
		for(int i=1;i<argc;i++){
			fstream f;
			f.open(argv[i]);
			if(f.fail()){
				cerr<<"The file "<<argv[i]<<" is invalid!"<<endl;
				return EXIT_FAILURE;
			}
			string str;
			vector<string> fIn;
			while(getline(f, str)){
				fIn.push_back(str);
			}
			sort(fIn.begin(), fIn.end());
			printElements<vector<string> >(fIn);
			f.close();
		}
	}
	return EXIT_SUCCESS;
}

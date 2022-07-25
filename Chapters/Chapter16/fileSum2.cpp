#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <sstream>
//#include <string>

using namespace std;

int main(int argc, char ** argv){
	if(argc==2){
		ifstream f;
		f.open(argv[1]);
		string s;
		int sum = 0;
		int num;
		stringstream ss;
		while(getline(f,s)){
			ss.str(s);
			if(!(ss>>num)){
				cerr<<"The format of input file is invalid!\n";
				return EXIT_FAILURE;
			}
			sum+=num;
			ss.clear();
		}
		cout<<"sum is:\n";
		cout<<sum<<endl;
		f.close();
	}
	else if(argc==1){
		int sum=0;
		int i;
		while(cin>>i){
			//cin>>i;
			sum+=i;
			if(cin.get()=='\n'){
				break;
			}	
		}
		while(cin.fail()){
			cerr<<"Input type is invalid!\n";
			return EXIT_FAILURE;
		}
		cout<<"sum is:\n";
		cout<<sum<<endl;
	}
	else{
		cerr<<"The input command argument is invalid!\n";
	}
	return EXIT_SUCCESS;
}

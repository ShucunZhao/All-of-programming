#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char ** argv){
	if(argc>1){
		for(int i=1;i<argc;i++){
			//FILE * f = fopen(argv[i], "r");
			ifstream f;
			f.open(argv[i]);
			if(!f.is_open()){
				cout<<"No file named "<<argv[i]<<" exit."<<endl;
				continue;
			}
			else{
				string s;
				while(f>>s){
					cout<<s;
				}
			}
			f.close();
		}
	}
	else{
		string str;
		cin>>str;
		cout<<str<<endl;
	}

	return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>
//#include <ctype.h>
//#include <string>

using namespace std;

int main(int argc, char ** argv){
	if(argc==2){
		FILE * f = fopen(argv[1], "r");
		char ** lines=NULL;
		char * cur=NULL;
		size_t linecap;
		size_t num=0;
		while(getline(&cur, &linecap, f)>=0){
			lines = (char**)realloc(lines, (num+1)*sizeof(char*));
			if(!isdigit(*cur)){
				cerr<<"The No."<<num<<" line of intput file is invalid!\n";
				return EXIT_FAILURE;
			}
			lines[num] = cur;
			cur = NULL;
			num++;
		}
		free(cur);
		int sum = 0;
		for(size_t i=0;i<num;i++){
			sum+=atoi(lines[i]);
			free(lines[i]);
		}
		free(lines);
		cout<<"sum is:\n";
		cout<<sum<<endl;
		if(fclose(f)!=0){
			cerr<<"file "<<argv[1]<<" failed to close!\n";
			return EXIT_FAILURE;
		}
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

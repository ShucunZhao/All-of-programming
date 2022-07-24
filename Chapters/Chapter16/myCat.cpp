#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char ** argv){
	if(argc>1){
		for(int i=1;i<argc;i++){
			FILE * f = fopen(argv[i], "r");
			if(f==NULL){
				cout<<"No file named "<<argv[i]<<" exit."<<endl;
				continue;
			}
			else{
				char ** lines=NULL;
				char * cur=NULL;
				size_t linecap;
				size_t num = 0;
				while(getline(&cur, &linecap, f)>=0){
					lines = (char**)realloc(lines, (num+1)*sizeof(char*));
					lines[num] = cur;
					//cout<<lines[num];
					//free(lines[num]);
					cur = NULL;
					num++;
				}
				free(cur);
				//free(lines);
				
				for(size_t j=0;j<num;j++){
					cout<<lines[j];
					free(lines[j]);
				}
				free(lines);
			}
			if(fclose(f)!=0){
				cout<<"file "<<argv[i]<<" couldn't close."<<endl;	
			}
		}
	}
	else{
		string str;
		cin>>str;
		cout<<str<<endl;
	}

	return EXIT_SUCCESS;
}

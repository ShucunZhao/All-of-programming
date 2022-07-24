#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <sstream>
#include "Q16.5.hpp"

MyatoiHex::MyatoiHex():str(NULL){

}

MyatoiHex::MyatoiHex(const std::string & strIn):str(strIn){

}

int MyatoiHex::myatoiHex(){
	int i = str.size();
	if(i==0){
		return 0;
	}
	int n = 0;	
	while(str[n]==' '||str[n]=='\n'||str[n]=='\t'||str[n]=='\r'||str[n]=='\f'||str[n]=='\b'){
		n++;
	}
	if((str[n]=='0'&&(str[n+1]=='x'||str[n+1]=='X'))&&n<i){
		n+=2;
		while(n<i){
			if(str[n]>='0'&&str[n]<='9'){
				result = result*16+str[n]-'0';
				if(result<0){
					result = INT_MAX;
					return result;
				}
				n++;
				continue;
			}
			else if(str[n]>='A'&&str[n]<='F'){
				result = result*16+str[n]-'A'+10;
				if(result<0){
					result = INT_MAX;
					return result;
				}
				n++;
				continue;
			}
			else if(str[n]>='a'&&str[n]<='f'){
				result = result*16+str[n]-'a'+10;
				if(result<0){
					result = INT_MAX;
					return result;
				}
				n++;
				continue;
			}
			else{
				return result;
			}
		}
	}
	else{
		return 0;
	}
	return result;
}

int MyatoiHex::atoiHexFromsstream(){
	std::stringstream sstream;
	sstream<<std::hex<<str;
	sstream>>result;
	return result;
}

int main(int argc, char ** argv){
	std::string str("  0xfffefffe");
	MyatoiHex * test = new MyatoiHex(str);
	std::cout<<"myatoiHex result:\n";
	std::cout<<test->myatoiHex()<<std::endl;
	std::cout<<"atoiHexFromsstream result:\n";
	std::cout<<test->atoiHexFromsstream()<<std::endl;
	delete test;
	return EXIT_SUCCESS;
}



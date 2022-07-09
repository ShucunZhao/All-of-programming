#include <cstdlib>
#include <iostream>
#include <sstream>
#include <climits>
#include "Q16.4.hpp"

Myatoi::Myatoi():str(NULL){

}

Myatoi::Myatoi(const std::string & s):str(s){

}

int Myatoi::myatoi(){//U need to add the boundary of the int type at last.
	int i = str.size();
	if(i==0){
		return 0;
	}
	//std::cout<<i<<std::endl;
	int n = 0;
	
	while(str[n]==' '||str[n]=='\n'||str[n]=='\t'||str[n]=='\r'||str[n]=='\f'||str[n]=='\b'){
		n++;
	}
		
	bool sign = 1;
	if(str[n]=='+'){
		n++;
	}
	if(str[n]=='-'){
		sign = 0;
		n++;
	}
	while(str[n]>='0'&&str[n]<='9'&&n<i){
		if(sign&&result<=INT_MAX){
			result = result*10+(str[n]-'0');
			if(result<0){
				result = INT_MAX;
				break;
			}
		}
		else if(sign&&result>INT_MAX){
			result = INT_MAX;
			break;
		}
		else if(!sign&&result<=INT_MIN){
			result = result*10+(str[n]-'0'); 
			if(result>0){
				result = INT_MAX;
			}
		}
		else{
			result = INT_MIN;
			break;
		}
		n++;
	}
	if(sign){
		return result;
	}
	else{
		return (-1)*result;
	}
	
	//return 0;
}

int Myatoi::atoiFromsstream(){
	std::stringstream sstream;
	sstream << str;
	sstream >> result;

	return result;
} 

int main(int argc, char ** argv){
	std::string str("-19786762345");
	/*
	std::stringstream sstream;
	int x;
	sstream << str;
	sstream >> x;
	*/
	Myatoi * test = new Myatoi(str);
	std::cout<<"sstream result:\n";
	std::cout<<test->atoiFromsstream()<<std::endl;
	std::cout<<"myatoi result:\n";
	std::cout<<test->myatoi()<<std::endl;
	delete test;
	return EXIT_SUCCESS;
}

#include <iostream>
using namespace std;

int g(int x, int y){
	switch(x - y){
		case 0:
			return x;
		case 4:
			y++;
			break;
		case 7:
			x--;
		case 9:
			return x*y;
		case 3:
			y = x+9;
		default:
			return y - x;
	}
	return y;
}

int main(){
	cout<<"The answer should be: "<<'\n'<<g(9,5)<<endl;
	cout<<g(3,0)<<endl;
	cout<<g(2,9)<<endl;
	cout<<g(5,5)<<endl;
	cout<<g(27,18)<<endl;
	return 0;
}

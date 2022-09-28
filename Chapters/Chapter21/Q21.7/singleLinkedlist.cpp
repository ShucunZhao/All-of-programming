#include <cstdlib>
//#include <iostream>
#include "singleLinkedlist.h"

using namespace std;

int main(int argc, char ** argv){
	SingleLinkedList<int> L1;
	SingleLinkedList<int> L2;
	for(int i=0;i<10;i++){
		L1.addFront(i);
	}
	cout<<"L1:"<<endl;
	L1.printData();
	L2 = L1;
	cout<<"L2:"<<endl;
	L2.printData();
	cout<<"L2[3]:"<<L2[3]<<endl;
	cout<<"Size of L2 is:"<<L2.getSize()<<endl;
	SingleLinkedList<int> L3(L1);
	cout<<"L3:"<<endl;
	L3.printData();
	cout<<"Size of L3 is:"<<L3.getSize()<<endl;
	cout<<"L3[3]:"<<L3[3]<<endl;
	L3.remove(3);
	cout<<"New size of L3 is:"<<L3.getSize()<<endl;
	cout<<"New L3[3]:"<<L3[3]<<endl;
	//int removeData = 100;
	int removeData = 3;
	if(L2.removeByP(removeData)){
		cout<<"Remove data "<<removeData<<" of L2 successfully."<<endl;
		cout<<"New size of L2 is:"<<L2.getSize()<<endl;
		cout<<"New L2[3]:"<<L2[3]<<endl;
	}
	else{
		cout<<"Cannot remove data "<<removeData<<" of L2."<<endl;
	}
	return EXIT_SUCCESS;
}

#include <cstdlib>
//#include <iostream>
#include "doubleLinkedlist.h"

using namespace std;

int main(int argc, char ** argv){
	DoubleLinkedList<int> L1;
	DoubleLinkedList<int> L2;
	for(int i=0;i<10;i++){
		L1.addFront(i);
	}
	for(int j=0;j<10;j++){
		L2.addBack(j);
	}
	cout<<"L1:"<<endl;
	L1.printData();
	cout<<"L2:"<<endl;
	L2.printData();
	DoubleLinkedList<int> L3(L1);
	cout<<"L3:"<<endl;
	L3.printData();
	L3 = L2;
	cout<<"new L3:"<<endl;
	L3.printData();
	cout<<"Size of L3 is:"<<L3.getSize()<<endl;
	cout<<"L3[0]:"<<L3[0]<<endl;
	cout<<"L3[9]:"<<L3[9]<<endl;
	cout<<"L3[3]:"<<L3[3]<<endl;
	return EXIT_SUCCESS;
}

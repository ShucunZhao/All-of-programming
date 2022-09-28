#include <cstdlib>
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
	cout<<"Size of L3:"<<L3.getSize()<<endl;
	cout<<"L3[0]:"<<L3[0]<<endl;
	const int find = 1;
	cout<<"index of "<<find<<" is:"<<L3.find(find)<<endl;
	/*
	//Remove test:
	int rem1 = 0, rem2 = 9, rem3 = 100;
	if(L3.remove(rem1)){
		cout<<"Remove data "<<rem1<<" successfully."<<endl;
		cout<<"New size of L3:"<<L3.getSize()<<endl;
		cout<<"New L3[0]:"<<L3[0]<<endl;
		cout<<"The data of head is: "<<L3.getHead()<<endl;
		cout<<"The data of tail is: "<<L3.getTail()<<endl;
	}
	else{
		cout<<"Failed to remove "<<rem1<<endl;
	}
	if(L3.remove(rem2)){
		cout<<"Remove data "<<rem2<<" successfully."<<endl;
		cout<<"New size of L3:"<<L3.getSize()<<endl;
		cout<<"New L3 last element:"<<L3[L3.getSize()-1]<<endl;
		cout<<"The data of head is: "<<L3.getHead()<<endl;
		cout<<"The data of tail is: "<<L3.getTail()<<endl;
	}
	else{
		cout<<"Failed to remove "<<rem2<<endl;
	}
	if(L3.remove(rem3)){
		cout<<"Remove data "<<rem3<<" successfully."<<endl;
		cout<<"New size of L3:"<<L3.getSize()<<endl;	
	}
	else{
		cout<<"Failed to remove "<<rem3<<endl;
	}
	*/
	return EXIT_SUCCESS;
}

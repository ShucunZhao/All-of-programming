#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList{
private:
	class Node{
	public:
		T data;
		Node * prev;
		Node * next;
		Node():prev(NULL),next(NULL){}
		Node(T & input, Node * inHead):data(input),prev(NULL),next(inHead){}
		Node(T & input, Node * inHead, Node * inNext):data(input),prev(inHead),next(inNext){}
	};
	Node * head;
	Node * tail;
	size_t size;
public:
	DoubleLinkedList():head(NULL),tail(NULL),size(0){}
	//Copy with reverse order(add from front):
	DoubleLinkedList(const DoubleLinkedList & rhs):head(NULL),tail(NULL),size(0){
	//U must use the initialization list to initial the head and tail into NULL here! 
	//Otherwise the head/tail would be allocate memory randomly which will cause the addFront/addBack function to judge the head mistake!
		/*
		//Method1: Start with head and add each element from back.
		Node * temp = rhs.head;
		while(temp!=NULL){
			this->addBack(temp->data);
			temp = temp->next; 
		}
		*/
		//Method2: Start with tail and add each element from front.
		Node * temp = rhs.tail;
		while(temp!=NULL){
			this->addFront(temp->data);
			temp = temp->prev; 
		}
	}
	DoubleLinkedList & operator=(const DoubleLinkedList & rhs){
		if(this==&rhs){
			return *this;
		}
		DoubleLinkedList temp(rhs);
		Node * srcHead = this->head;
		Node * srcTail = this->tail;
		//size_t srcSize = this->size;
		this->head = temp.head;
		this->tail = temp.tail;
		this->size = temp.size;
		temp.head = srcHead;
		temp.tail = srcTail;
		//temp.size = 
		return *this;
	}
	~DoubleLinkedList(){
		while(head!=NULL){
			Node * temp = head->next;
			delete head;
			head = temp;
		}
	}
	void addFront(T & data){
		head = new Node(data,head);
		if(tail==NULL){
			tail=head;
		}
		else{
			head->next->prev = head;
		}
		size++;
	}
	void addBack(T & data){
		
		tail = new Node(data,tail, NULL);
		if(head==NULL){
			head = tail;
		}
		else{
			tail->prev->next = tail;
		}
		
		/*
		Node * node = new Node(data,tail,NULL);
		if(size==0){
			head = node;
			tail = node;
		}
		else{
			tail->next = node;
			tail = node;
		}
		*/
		size++;
	}
	void printData() const{
		Node * temp = head;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	}
	size_t getSize()const{
		return this->size;
	}
	T & operator[](size_t index){
		if(index==0){
			return head->data;
		}
		else if(index==size-1){
			return tail->data;
		}
		else{
			Node * temp = head;
			while(index--){
				temp = temp->next;
			}
			return temp->data;
		}
	}
	T & operator[](size_t index)const{
		if(index==0){
			return head->data;
		}
		else if(index==size-1){
			return tail->data;
		}
		else{
			Node * temp = head;
			while(index--){
				temp = temp->next;
			}
			return temp->data;
		}
	}
};

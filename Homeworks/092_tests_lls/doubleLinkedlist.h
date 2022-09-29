#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__
#include <cstdlib>
#include <iostream>
#include <exception>

using namespace std;

class indexException : public exception{
public:
	virtual const char * what()const throw(){
		return "Index is valid!\n";
	}
}; 


template<typename T>
class DoubleLinkedList{
public:
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

	class const_iterator{
		const Node * current;
	public:
		const_iterator():current(NULL){}
		explicit const_iterator(const Node * c):current(c){}
		const_iterator & operator++(){//This means ++i
			current = current->next;
			return *this;
		}
		const_iterator & operator++(int){//This means i++
			const_iterator ans(this->current);
			current = current->next;
			return ans;
		}
		const T & operator*()const{
			return current->data;
		}
		const T * operator->()const{
			return &current->data;
		}
		bool operator!=(const const_iterator & rhs)const{
			return current!=rhs.current;
		}
		bool operator==(const const_iterator & rhs)const{
			return current==rhs.current;
		}
	};
	class iterator{
		Node * current;
	public:
		iterator():current(NULL){}
		explicit iterator(Node * c):current(c){}
		iterator & operator++(){//This means ++i
			current = current->next;
			return *this;
		}
		iterator & operator++(int){//This means i++
			iterator ans(this->current);
			current = current->next;
			return ans;
		}
		T & operator*()const{
			return current->data;
		}
		T * operator->()const{
			return &current->data;
		}
		bool operator!=(const iterator & rhs)const{
			return current!=rhs.current;
		}
		bool operator==(const iterator & rhs)const{
			return current==rhs.current;
		}
	};
		const_iterator beginC() const{
			return const_iterator(head);
		}
		const_iterator endC() const{
			return const_iterator(NULL);
		}
		iterator begin(){
			return iterator(head);
		}
		iterator end(){
			return iterator(NULL);
		}
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
	void addFront(T data){
		head = new Node(data,head);
		if(tail==NULL){
			tail=head;
		}
		else{
			head->next->prev = head;
		}
		size++;
	}
	void addBack(T data){	
		tail = new Node(data,tail, NULL);
		if(head==NULL){
			head = tail;
		}
		else{
			tail->prev->next = tail;
		}
		size++;
	}
	
	bool remove(T data){
		Node ** cur = &head;
		while((*cur)!=NULL&&(*cur)->data!=data){
			cur = &(*cur)->next;
		}
		if((*cur)==NULL){
			return 0;
		}
		Node * temp = *cur;
		if((*cur)->next==NULL){
			tail = (*cur)->prev;
			*cur = NULL;	
		}
		else{
			*cur = (*cur)->next;
		}
		delete temp;
		size--;
		return 1;
	}

	int find(const T & data)const{
		if(head==NULL){
			return -1;
		}
		int i=0;
		Node * cur = head;
		while(cur!=NULL&&cur->data!=data){
			cur = cur->next;
			i++;
		}
		if(cur==NULL){
			return -1;
		}
		return i;
	}
	
	DoubleLinkedList<T> * reverse(){
		DoubleLinkedList<T> * ans = new DoubleLinkedList<T>;
		for(DoubleLinkedList<T>::iterator it = this->begin();it!=this->end();++it){
			ans->addFront(*it);
		}
		return ans;
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
		if(index<0||index>size-1){
			throw indexException();
		}
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
		
		if(index<0||index>size-1){
			throw indexException();
		}
		
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
	
	T & getHead()const{
		return head->data;
	}
	T & getTail()const{
		return tail->data;
	}
	template<typename X> friend std::ostream & operator<<(std::ostream & stream, const DoubleLinkedList<X> & list);//Key Point: you must declare operator << as the friend method here and the typename cannot be the same as this parent class(here cannot be typename 'T').
	//template<typename Y> friend DoubleLinkedList & reverse(const DoubleLinkedList<Y> & rhs);

};


template<typename T>
std::ostream & operator<<(std::ostream & stream, const DoubleLinkedList<T> & list){
	stream<<"[";
	string comma = "";
	typename DoubleLinkedList<T>::const_iterator it = list.beginC();
	while(it!=list.endC()){
		stream<<comma<<*it;
		comma = ",";
		++it;
	}
	stream<<"]";
	return stream;
}

/*
template<typename T>
DoubleLinkedList<T> & reverse(const DoubleLinkedList<T> & rhs){
		DoubleLinkedList<T> ans;
		for(typename DoubleLinkedList<T>::const_iterator it = rhs.beginC();it!=rhs.endC();++it){
			ans.addFront(*it);
		}
		return ans;
	}
*/

#endif

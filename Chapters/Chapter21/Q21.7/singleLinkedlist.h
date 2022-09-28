#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__
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
class SingleLinkedList{
private:
	class Node{
	public:
		T data;
		Node * next;
		Node():next(NULL){}
		Node(T & input, Node * inHead):data(input),next(inHead){}
	};
	Node * remove(const T & data, Node * current){
		if(current==NULL){
			return NULL;
		}
		if(data==current->data){
			Node * ans = current->next;
			size--;
			delete current;
			return ans;
		}
		current->next = remove(data, current->next);
		return current;
	}
	Node * head;
	size_t size;
public:
	SingleLinkedList():head(NULL),size(0){}
	//Copy with reverse order(add from front):
	SingleLinkedList(const SingleLinkedList & rhs):head(NULL),size(0){
		Node * temp = rhs.head;
		while(temp!=NULL){
			this->addFront(temp->data);
			temp = temp->next; 
		}
	}
	SingleLinkedList & operator=(const SingleLinkedList & rhs){
		if(this==&rhs){
			return *this;
		}
		SingleLinkedList temp(rhs);
		Node * srcHead = this->head;
		this->head = temp.head;
		this->size = temp.size;
		temp.head = srcHead;
		return *this;
	}
	~SingleLinkedList(){
		while(head!=NULL){
			Node * temp = head->next;
			delete head;
			head = temp;
		}
	}

	void addFront(T & data){
		head = new Node(data,head);
		size++;
	}

	void remove(const T & data){
		head = remove(data, head);
	}

	//U must use handle the address value of pointer rather than the real value here:
	//Because after this function return the frame of the value will be free so that
	//the value of pointer cur point to will alse be free so the cur value will be dangling.
	bool removeByP(const T & data){
		//Node * cur = head;//Key Point: cannot use pointer to handle value, 
		//should use pointer point to the pointer to change the value of address rather than 
		//the real value!
		Node ** cur = &head;
		if(cur==NULL){
			return 0;
		}
		while((*cur)->data!=data){
			cur = &(*cur)->next;
		}
		Node * temp = *cur;
		if((*cur)->next==NULL){
			*cur = NULL;
		}
		else{
			*cur = (*cur)->next;	
		}
		delete temp;
		size--;
		return 1;
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
		Node * temp = head;
		while(index--){
			temp = temp->next;
		}
		return temp->data;
	}

	T & operator[](size_t index)const{
		
		if(index<0||index>size-1){
			throw indexException();
		}
		if(index==0){
			return head->data;
		}
		Node * temp = head;
		while(index--){
			temp = temp->next;
		}
		return temp->data;
	}
};

#endif

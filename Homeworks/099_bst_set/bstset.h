#ifndef __BSTSET_H__
#define __BSTSET_H__
#include "set.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>

template<typename T>
class BstSet:public Set<T>{
private:
	class Node{
	public:
		T key;
		Node * left;
		Node * right;
		Node():key(0),left(NULL),right(NULL){}
		Node(T In):key(In),left(NULL),right(NULL){}
	};
	Node * root;
	
public:
	BstSet<T>():root(NULL){}
	BstSet(const BstSet & rhs){
		root = copyHelper(rhs.root);
	}
	Node * copyHelper(Node * cur){
		if(cur==NULL){
			return NULL;
		}
		Node * copy = new Node(cur->key);
		copy->left = copyHelper(cur->left);
		copy->right = copyHelper(cur->right);
		return copy;
	}
	BstSet & operator=(const BstSet & rhs){
		if(this!=&rhs){
			destroy(root);
			root = copyHelper(rhs.root);
		}
		return *this;
	} 
	~BstSet(){
		destroy(root);
	}
	void destroy(Node * cur){
		if(cur!=NULL){
			destroy(cur->left);
			destroy(cur->right);
			delete cur;
		}
	}
	virtual void add(const T & In){
		Node ** cur = &root;
		while((*cur)!=NULL){
			if((*cur)->key==In){
				return;
			}
			if((*cur)->key>In){
				cur = &(*cur)->left;
			}
			else{
				cur = &(*cur)->right;
			}
		}
		*cur = new Node(In);
	}
	virtual bool contains(const T & In)const{
		Node * cur = root;
		while(cur!=NULL){
			if(cur->key==In){
				return true;
			}
			else if(cur->key>In){
				cur = cur->left;
			}
			else{
				cur = cur->right;
			}
		}
		return false;
	}
	virtual void remove(const T & In){
		Node ** cur = &root;
		Node * temp = NULL;
		while((*cur)!=NULL){
			if((*cur)->key==In){
				if((*cur)->left==NULL){
					temp = (*cur)->right;
					delete *cur;
					*cur = temp;
				}
				else if((*cur)->right==NULL){
					temp = (*cur)->left;
					delete *cur;
					*cur = temp;
				}
				else{
					Node ** replace = cur;
					cur = &(*cur)->left;
					while((*cur)->right!=NULL){
						cur = &(*cur)->right;
					}
					(*replace)->key = (*cur)->key;
					temp = (*cur)->left;
					delete *cur;
					*cur = temp;
				}
			}
			else if((*cur)->key>In){
				cur = &(*cur)->left;
			}
			else{
				cur = &(*cur)->right;
			}
		}
	}
	void printInorder(){
		inOrder(root);
		std::cout<<std::endl;
	}
	void inOrder(Node * cur){
		if(cur!=NULL){
			inOrder(cur->left);
			std::cout<<cur->key<<" ";
			inOrder(cur->right);
		}
	}
};

#endif

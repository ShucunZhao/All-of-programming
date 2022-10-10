#include "map.h"
#include <iostream>

template<typename K, typename V>
class BstMap:public Map<K,V>{
private:
	class Node{
	public:
		K key;
		V value;
		Node * left;
		Node * right;
		Node():key(0),value(0),left(NULL),right(NULL){}
		Node(K k, V v):key(k),value(v),left(NULL),right(NULL){}
	};
	Node * root;

public:
	BstMap<K,V>():root(NULL){}
	BstMap<K,V>(const BstMap & rhs):root(NULL){
		root = copyHelper(rhs.root);
	}
	Node * copyHelper(Node * cur){
		if(cur==NULL){
			return NULL;
		}
		Node * copy = new Node(cur->key, cur->value);
		copy->left = copyHelper(cur->left);
		copy->right = copyHelper(cur->right);
		return copy;
	}
	~BstMap<K,V>(){
		destroy(root);
	}
	BstMap & operator=(const BstMap & rhs){
		if(this!=&rhs){
			destroy(root);
			root = copyHelper(rhs.root);
		}
		return *this;
	}
	void destroy(Node * cur){
		if(cur!=NULL){
			destroy(cur->left);
			destroy(cur->right);
			delete cur;
		}
	}

	virtual void add(const K & key, const V & value){
		Node ** cur = &root;
		while(*cur!=NULL){
			if(key==(*cur)->key){
				(*cur)->value = value;
				return;
			}
			if(key<(*cur)->key){
				cur = &(*cur)->left;
			}
			else{
				cur = &(*cur)->right;
			}
		}
		*cur = new Node(key, value);
	}

	virtual const V & lookup(const K & key) const throw (std::invalid_argument){
		Node * cur = root;
		while(cur!=NULL){
			if(key==cur->key){
				return cur->value;
			}
			if(key<cur->key){
				cur = cur->left;
			}
			else{
				cur = cur->right;
			}
		}
		throw std::invalid_argument("The key does not exist!\n");
	}

	virtual void remove(const K & key){
		Node ** cur = &root;
		Node * temp = NULL;
		while(*cur!=NULL){
			if((*cur)->key==key){
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
					(*replace)->value = (*cur)->value;
					temp = (*cur)->left;
					delete (*cur);
					*cur = temp;
				}
			}
			else if(key<(*cur)->key){
				cur = &(*cur)->left;
			}
			else{
				cur = &(*cur)->right;
			}
		}
	}

	void inOrderRecur(Node * cur){
		if(cur!=NULL){
			inOrderRecur(cur->left);
			std::cout<<"("<<cur->key<<","<<cur->value<<")"<<std::endl;
			inOrderRecur(cur->right);
		}
	}

	void inOrderPrint(){
		inOrderRecur(root);
	}
};

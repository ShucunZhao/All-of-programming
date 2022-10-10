#ifndef __BST_H__
#define __BST_H__
#include <cstdlib>
#include <cstdio>
#include <iostream>

template<typename T>
class Bst{
private:
	class Node{
	public:
		T val;
		Node * left;
		Node * right;
		explicit Node(T In):val(In),left(NULL),right(NULL){}
	};
	Node * root;
	template<bool removeAll>
	Node * remove(Node * cur, const T & In){
		if(cur==NULL){
			return NULL;
		}	
		if(cur->val==In){
			Node * ans;
			if(removeAll){
				ans = remove<removeAll>(cur->left, In);
				ans = remove<removeAll>(cur->right, In);
			}
			else{
				ans = cur->left;
			}
			return ans;
		}
		else if(cur->val < In){
			cur->right = remove<removeAll>(cur->right, In);
		}
		else{
			cur->left = remove<removeAll>(cur->left, In);
		}
		return cur;
	}
public:
	Bst():root(NULL){}
	Bst(const Bst & rhs):root(NULL){
		root = copyHelper(rhs.root);
	}
	Node * copyHelper(Node * cur){
		if(cur==NULL){
			return NULL;
		}
		Node * copy = new Node(cur->val);
		copy->left = copyHelper(cur->left);
		copy->right = copyHelper(cur->right);
		return copy;
	}
	Bst & operator=(const Bst & rhs){
		if(this!=&rhs){
			destroy(root);
			root = copyHelper(rhs.root);
		}
		return *this;
	}
	~Bst(){
		destroy(root);
	}
	void destroy(Node * cur){
		if(cur!=NULL){
			destroy(cur->left);
			destroy(cur->right);
			delete cur;
		}
	}
	void add(T In){
		root = addHelper(root, In);
	}
	Node * addHelper(Node * cur, T toAdd){
		if(cur==NULL){
			Node * ans = new Node(toAdd);
			return ans;
		}
		else if(toAdd<cur->val){
			Node * newLeft = addHelper(cur->left, toAdd);
			cur->left = newLeft;
		}
		else{
			Node * newRight = addHelper(cur->right, toAdd);
			cur->right = newRight;
		}
		return cur;
	}
	Node * find(const T & In){
		Node * ans = findHelper(root, In);
		if(ans==NULL){
			throw std::invalid_argument("The key does not exist!\n");
		}
		return ans;
	}
	Node * findHelper(Node * cur, const T & In){
		if(cur==NULL){
			return NULL;
		}
		else if(cur->val==In){
			return cur;
		}
		else if(cur->val<In){
			cur = cur->right;
			return findHelper(cur, In);
		}
		else{
			cur = cur->left;
			return findHelper(cur, In);
		}
	}
	void remove(const T & In){
		root = remove<false>(root, In);
	}
	void removeAll(const T & In){
		root = remove<true>(root, In);
	}
	void printInorder(){
		inOrder(root);
		std::cout<<std::endl;
	}
	void inOrder(Node * cur){
		if(cur!=NULL){
			inOrder(cur->left);
			std::cout<<cur->val<<" ";
			inOrder(cur->right);
		}
	}
};

#endif

#pragma once
#include <iostream>

template<typename T>
class BinTreeIterator;

template<typename T>
class BinTree{
	struct Node{
		T value;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(T val, Node* l, Node* r) : value(val), left(l), right(r){}
	};

	Node* root = nullptr;
	Node* findParentFor(T val);

	friend class BinTreeIterator<T>;
public:	
	void insert(T val);
};

template<typename T>
void BinTree<T>::insert(T val){
	if(root == nullptr){
		root = new Node(val, nullptr, nullptr);
	}
	else{
		Node* parentNode = findParentFor(val);
		if(val < parentNode->value)
			parentNode->left = new Node(val, nullptr, nullptr);
		else
			parentNode->right = new Node(val, nullptr, nullptr);
	}
}	

template<typename T>
typename BinTree<T>::Node* BinTree<T>::findParentFor(T val){
	Node* child = root;
	Node* parent = nullptr;

	while(child != nullptr){
		parent = child;
		if(val < root->value)
			child = child->left;
		else
			child = child->right;
	}
	return parent;
}

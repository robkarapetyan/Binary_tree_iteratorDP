#pragma once
#include <vector>
#include "BinTree.h"


template<typename T>
class BinTreeIterator{
public:
	explicit BinTreeIterator(const BinTree<T>& tree);
	void first();
	void next();
	bool isDone();
	const T& currentItem();

	size_t index = 0;
private:
	std::vector<T> treeNodes = {};
	void inorderTraverse(typename BinTree<T>::Node* nodeToStart);
};

template<typename T>
BinTreeIterator<T>::BinTreeIterator(const BinTree<T>& tree){
	inorderTraverse(tree.root);
}

template<typename T>
void BinTreeIterator<T>::first(){
	index = 0;
}

template<typename T>
void BinTreeIterator<T>::next(){
	index++;
}

template<typename T>
const T& BinTreeIterator<T>::currentItem(){
	if(index < treeNodes.size()){
		return treeNodes[index];
	}
}

template<typename T>
bool BinTreeIterator<T>::isDone(){
	if(index == treeNodes.size())
		return true;
	return false;
}

template<typename T>
void BinTreeIterator<T>::inorderTraverse(typename BinTree<T>::Node* nodeToStart){
	if(nodeToStart == nullptr)
		return;

	inorderTraverse(nodeToStart->left);
	treeNodes.push_back(nodeToStart->value);
	inorderTraverse(nodeToStart->right);
}


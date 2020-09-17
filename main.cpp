#include "BinTree.h"
#include "BinTreeIter.h"

int main() {
	BinTree<int> tree1;
	tree1.insert(5);
	tree1.insert(4);
	tree1.insert(600);

	BinTreeIterator<int> iter(tree1);

	while(!iter.isDone()){
		std::cout << iter.currentItem() << std::endl;
		iter.next();
	}
	
	
	return 0;
}

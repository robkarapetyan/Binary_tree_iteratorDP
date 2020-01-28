#include <iostream>
#include <vector>

class BinTree {
	struct Node {
		int value = 0;
		Node* left = nullptr;
		Node* right = nullptr;

		Node(Node* l, Node* r, int val): value(val), left(l), right(r){}
	};

	Node* head = nullptr;
	void insert(int a, Node* nodetoinsert);

public:
	void insert(int key);
	

	class Iterator {
		Node* m_root = nullptr;
		std::vector<int> nodes;
		size_t index = 0;
	public:

		Iterator(BinTree* tree) : m_root(tree->head){
			InorderTraverse(tree->head);
		}

		void update() {
			nodes.clear();
			InorderTraverse(m_root);
		}

		int next() {
			return nodes[index++];
			
		}

		void reset() {
			index = 0;
		}

		bool isEnd() {
			return index == nodes.size() ?  true : false;
		}

		bool hasNext() {
			
			if (index + 1 < nodes.size())
				return true;
			else
				return false;
		}

		void InorderTraverse(Node* root){
			if (root == nullptr)
				return;
			InorderTraverse(root->left);

			nodes.push_back(root->value);

			InorderTraverse(root->right);
		}
	};
};


void BinTree::insert(int a, Node* nodetoinsert)
{
	if (nodetoinsert->value > a) {
		if (nodetoinsert->left)
		{
			insert(a, nodetoinsert->left);
		}
		else {
			nodetoinsert->left = new Node(nullptr, nullptr, a);
		}
	}
	else {
		if (nodetoinsert->right)
		{
			insert(a, nodetoinsert->right);
		}
		else {
			nodetoinsert->right = new Node(nullptr, nullptr, a);
		}
	}
		
}

void BinTree::insert(int key)
{
	if (!head) {
		head = new Node(nullptr, nullptr, key);
		return;
	}
	insert(key, head);
}



int main() {
	BinTree tree1;
	tree1.insert(5);
	tree1.insert(4);
	tree1.insert(600);

	BinTree::Iterator iter(&tree1);

	tree1.insert(8);
	iter.update();

	while(!iter.isEnd())
	std::cout << iter.next() << " ";
	
	
	return 0;
}
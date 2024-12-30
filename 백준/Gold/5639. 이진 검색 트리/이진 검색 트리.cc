#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

class node {
public:
	int value = 0;
	node* left = nullptr;
	node* right = nullptr;
};


class bst {
private:
	node* root;
public:
	bst();
	bst(int num) {
		node* temp = new node;
		temp->value = num;
		temp->left = nullptr;
		temp->right = nullptr;
		root = temp;
	};

	void insert(node* n, int num) {

		if (n->value > num) {
			if (n->left == nullptr) {
				node* temp = new node;
				temp->value = num;
				n->left = temp;
				return;
			}
			else {
				insert(n->left, num);
			}
		}
		else if (n->value < num){
			if (n->right == nullptr) {
				node* temp = new node;
				temp->value = num;
				n->right = temp;
				return;
			}
			else {
				insert(n->right, num);
			}
		}
	}

	void postorder_traverse(node *n) {
		if (n->left != nullptr)
			postorder_traverse(n->left);
		if (n->right != nullptr)
			postorder_traverse(n->right);
		cout<<n->value<<"\n";
	}

	node* getRoot() {
		return this->root;
	}

};



int main() {
	int input_num = 0;
	cin >> input_num;
	bst b(input_num);
	while (cin >> input_num) {
		b.insert(b.getRoot(), input_num);
	}
	b.postorder_traverse(b.getRoot());
	return 0;
}
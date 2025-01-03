#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

class node {
public:
	char name = '-';
	node* left = nullptr;
	node* right = nullptr;
};
class Btree {
private:
	node* root;

public:
	Btree();
	Btree(char c) {
		node* temp = new node;
		temp->name = c;
		root = temp;
	}
	node* getRoot() {
		return this->root;
	}
	void insert(node* nodeptr, char p, char l, char r) {
		if (nodeptr->name == p) {
			if (l != '.') {
				node* temp = new node;
				temp->name = l;
				nodeptr->left = temp;
			}
			if (r != '.') {
				node* temp = new node;
				temp->name = r;
				nodeptr->right = temp;
			}
			
		}
		else {
			if (nodeptr->left != nullptr) {
				this->insert(nodeptr->left, p, l, r);
			}
			if (nodeptr->right != nullptr) {
				this->insert(nodeptr->right, p, l, r);
			}
		}
		return;
	}

	void preOrder(node* nodeptr) {
		if (nodeptr == nullptr) {
			return;
		}
		cout<<nodeptr->name;
		preOrder(nodeptr->left);
		preOrder(nodeptr->right);
	}

	void inOrder(node* nodeptr) {
		if (nodeptr == nullptr) {
			return;
		}
		inOrder(nodeptr->left);
		cout << nodeptr->name;
		inOrder(nodeptr->right);
	}

	void postOrder(node* nodeptr) {
		if (nodeptr == nullptr) {
			return;
		}
		postOrder(nodeptr->left);
		postOrder(nodeptr->right);
		cout << nodeptr->name;
	}

};


int main() {
	int N = 0;
	cin >> N;
	Btree btree('A');
	node* root = btree.getRoot();
	for(int i=0; i<N;i++) {
		char p, l, r;
		cin >> p >> l >> r;
		btree.insert(root, p, l, r);
	}
	btree.preOrder(root);
	cout << "\n";
	btree.inOrder(root);
	cout << "\n";
	btree.postOrder(root);
	return 0;
}
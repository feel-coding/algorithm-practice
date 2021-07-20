#include <iostream>
using namespace std;

int leftChild[101];
int rightChild[101];

void preorder(int node) {
	cout << node << " ";
	if (leftChild[node] != -1) preorder(leftChild[node]);
	if (rightChild[node] != -1) preorder(rightChild[node]);
}

void inorder(int node) {
	if (leftChild[node] != -1) inorder(leftChild[node]);
	cout << node << " ";
	if (rightChild[node] != -1) inorder(rightChild[node]);
}

void postorder(int node) {
	if (leftChild[node] != -1) postorder(leftChild[node]);
	if (rightChild[node] != -1) postorder(rightChild[node]);
	cout << node << " ";
}

int main() {
	int n;
	cin >> n;
	int node;
	for (int i = 0; i < n; i++) {
		cin >> node;
		cin >> leftChild[node] >> rightChild[node];
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	return 0;
}

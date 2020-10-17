#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

map<char, pair<char, char>> m;

void preorder(char node) {
	cout << node;
	if (m[node].first != '.') {
		preorder(m[node].first);
	}
	if (m[node].second != '.') {
		preorder(m[node].second);
	}
}
void inorder(char node) {
	if (m[node].first != '.') {
		inorder(m[node].first);
	}
	cout << node;
	if (m[node].second != '.') {
		inorder(m[node].second);
	}
}
void postorder(char node) {
	if (m[node].first != '.') {
		postorder(m[node].first);
	}
	if (m[node].second != '.') {
		postorder(m[node].second);
	}
	cout << node;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char node, left, right;
		cin >> node >> left >> right;
		m[node] = make_pair(left, right);
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	return 0;
}
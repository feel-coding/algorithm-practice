#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x, y, a, b;
	int parent[1005];
	cin >> n >> x >> y;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		parent[b] = a;
	}
	vector<int> xParents;
	vector<int> yParents;
	xParents.push_back(x);
	yParents.push_back(y);
	int currentNode = x;
	while (true) {
		currentNode = parent[currentNode];
		xParents.push_back(currentNode);
		if (currentNode == 0) break;
	}
	currentNode = y;
	while (true) {
		currentNode = parent[currentNode];
		yParents.push_back(currentNode);
		if (currentNode == 0) break;
	}
	for (int i = 0; i < xParents.size(); i++) {
		for (int j = 0; j < yParents.size(); j++) {
			if (xParents[i] == yParents[j]) {
				cout << i + j;
				return 0;
			}
		}
	}
	return 0;
}

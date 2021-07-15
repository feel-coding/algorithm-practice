#include <iostream>
using namespace std;

int parent[1005];

int main() {
	int n, x, y, a, b;
	cin >> n >> x >> y;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		parent[b] = a; // b의 부모는 a이다.

	}
	int xParents[1005];
	int xParentsSize = 0;
	int yParents[1005];
	int yParentsSize = 0;
	int currentNode = x;
	while (true) {
		currentNode = parent[currentNode];
		xParents[xParentsSize++] = currentNode;
		if (currentNode == 0) break;
	}
	currentNode = y;
	while (true) {
		currentNode = parent[currentNode];
		yParents[yParentsSize++] = currentNode;
		if (currentNode == 0) break;
	}
	for (int i = 0; i < xParentsSize; i++) {
		for (int j = 0; j < yParentsSize; j++) {
			if (xParents[i] == yParents[j]) {
				cout << xParents[i];
				return 0;
			}
		}
	}
	return 0;
}

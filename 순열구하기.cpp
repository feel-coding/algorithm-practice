#include <iostream>
using namespace std;

int n, r;
char result[10];
bool visited[11] = { 0 };

void getResult(int current) {
	if (current == r) {
		for (int i = 0; i < r; i++) {
			cout << result[i];
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[current] = 'a' + i;
			getResult(current + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> r;
	getResult(0);
	return 0;
}

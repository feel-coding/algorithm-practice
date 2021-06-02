#include <iostream>
using namespace std;

int n;
int result[15];

void getResult(int current) {
	if (current == n) {
		for (int i = 0; i < n; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}
	result[current] = 0;
	getResult(current + 1);
	result[current] = 1;
	getResult(current + 1);
}

int main() {
	cin >> n;
	getResult(0);
	return 0;
}

#include <iostream>
using namespace std;

int n;
int result[100];
int foundAnswer = false;

bool isPossible(int index) {
	int cnt = 0;
	for (int length = 1; length <= (index + 1) / 2; length++) {
		bool flag = false;
		for (int i = index; i > index - length; i--) {
			if (result[i] != result[i - length]) {
				flag = true;
				break;
			}
		}
		if (flag) cnt++;
	}
	if (cnt == (index + 1) / 2) return true;
	else return false;
}

void getResult(int current) {
	if (foundAnswer) return;
	if (current == n) {
		for (int i = 0; i < n; i++) {
			cout << result[i];
		}
		foundAnswer = true;
		return;
	}
	result[current] = 1;
	if (isPossible(current)) {
		getResult(current + 1);
	}
	result[current] = 2;
	if (isPossible(current)) {
		getResult(current + 1);
	}
	result[current] = 3;
	if (isPossible(current)) {
		getResult(current + 1);
	}
}

int main() {
	cin >> n;
	getResult(0);
	return 0;
}

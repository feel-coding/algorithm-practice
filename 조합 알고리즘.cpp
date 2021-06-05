#include <iostream>
using namespace std;

int k;
int index = 0;
int result[10];

void getResult(int current) {
	if (current == 10) {
		index++;
		if (index == k) {
			for (int i = 0; i < 10; i++) {
				cout << result[i] << " ";
			}
		}
		return;
	}
	for (int i = 1; i <= 4; i++) {
		result[current] = i;
		getResult(current + 1);
	}
}

int main() {
	cin >> k;
	getResult(0);
	return 0;
}

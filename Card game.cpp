#include <iostream>
using namespace std;

int main() {
	int a[10];
	int b[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> b[i];
	}
	int aScore = 0;
	int bScore = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			aScore++;
		}
		else if (b[i] > a[i]) {
			bScore++;
		}
	}
	if (aScore > bScore) {
		cout << "A";
	}
	else if (bScore > aScore) {
		cout << "B";
	}
	else {
		cout << "D";
	}
	return 0;
}

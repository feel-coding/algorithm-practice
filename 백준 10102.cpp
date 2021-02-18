#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	char aOrB;
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		cin >> aOrB;
		if (aOrB == 'A') {
			a++;
		}
		else {
			b++;
		}
	}
	if (a > b) {
		cout << 'A';
	}
	else if (b > a) {
		cout << 'B';
	}
	else {
		cout << "Tie";
	}
	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* numbers = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	int* lds = new int[n];
	int maxLength = 0;
	for (int i = 0; i < n; i++) {
		int longestLength = 0;
		for (int j = 0; j < i; j++) {
			if (numbers[i] < numbers[j]) {
				if (lds[j] > longestLength)
					longestLength = lds[j];
			}
		}
		lds[i] = longestLength + 1;
		if (lds[i] > maxLength)
			maxLength = lds[i];
	}
	cout << maxLength;
	return 0;
}
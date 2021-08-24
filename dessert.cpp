#include <iostream>
using namespace std;

int n;
char operators[20];
int cnt = 0;

void getResult(int current) {
	if (current == n - 1) {
		int numbers[20];
		char realOperators[20];
		numbers[0] = 1;
		int index = 0;
		for (int i = 2; i <= n; i++) {
			if (operators[i - 2] == '.') {
				if (i >= 10) {
					numbers[index] = numbers[index] * 100 + i;
				}
				else {
					numbers[index] = numbers[index] * 10 + i;
				}
			}
			else {
				realOperators[index] = operators[i - 2];
				index++;
				numbers[index] = i;
			}
		}
		long long result = numbers[0];
		for (int i = 0; i < index; i++) {
			if (realOperators[i] == '+') {
				result += numbers[i + 1];
			}
			else {
				result -= numbers[i + 1];
			}
		}
		if (result == 0) {
			cnt++;
			if (cnt <= 20) {
				for (int i = 0; i < n - 1; i++) {
					cout << i + 1 << " " << operators[i] << " ";
				}
				cout << n << '\n';
			}
		}
		return;
	}
	operators[current] = '+';
	getResult(current + 1);
	operators[current] = '-';
	getResult(current + 1);
	operators[current] = '.';
	getResult(current + 1);
}

int main() {
	cin >> n;
	getResult(0);
	cout << cnt;
	return 0;
}

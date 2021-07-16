#include <iostream>
using namespace std;

int stack[101];
int top = -1;

int main() {
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			if (top >= n - 1) {
				cout << "Overflow\n";
			}
			else {
				stack[++top] = b;
			}
		}
		else if (a == 2) {
			if (top >= 0) {
				top--;
			}
			else {
				cout << "Underflow\n";
			}
		}
		else if (a == 3) {
			if (top >= 0) {
				cout << stack[top] << '\n';
			}
			else {
				cout << "NULL\n";
			}
		}
	}
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int n, m, a, b;
	int queue[105];
	int front = 0;
	int rear = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			if (rear < n) {
				queue[rear++] = b;
			}
			else {
				cout << "Overflow\n";
			}
		}
		else if (a == 2) {
			if (front == rear) {
				cout << "Underflow\n";
			}
			else {
				front++;
			}
		}
		else if (a == 3) {
			if (front == rear) {
				cout << "NULL\n";
			}
			else {
				cout << queue[front] << '\n';
			}
		}
	}
	return 0;
}

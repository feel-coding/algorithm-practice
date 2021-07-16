#include <iostream>
using namespace std;

int queue[105];

int main() {
	int n, m;
	int front = 0;
	int rear = 0;
	int cnt = 0;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			if (cnt == n) {
				cout << "Overflow\n";
			}
			else {
				queue[rear] = b;
				rear = (rear + 1) % n;
				cnt++;
			}
		}
		else if (a == 2) {
			if (cnt == 0) {
				cout << "Underflow\n";
			}
			else {
				front = (front + 1) % n;
				cnt--;
			}
		}
		else if (a == 3) {
			if (cnt == 0) {
				cout << "NULL\n";
			}
			else {
				cout << queue[front] << '\n';
			}
		}
	}
	return 0;
}

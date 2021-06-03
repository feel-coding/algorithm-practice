#include <iostream>
using namespace std;

int scores[] = { 0, 5, 10, 15, 20, 50, 30, 35, 40, 45, 100, 55, 60, 65, 70, 75, 80, 85, 90, 95, 500, 1000 };

int main() {
	int n, move;
	int current = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> move;
		current += move;
		if (current >= 21) {
			cout << 1000;
			break;
		}
		else {
			cout << scores[current] << " ";
		}
	}
	return 0;
}

#include <iostream>
using namespace std;

void draw(int n) {
	if (n == 1) {
		cout << 1;
		return;
	}
	draw(n - 1);
	cout << n;
	draw(n - 1);
}

int main() {
	int n;
	cin >> n;
	draw(n);
	return 0;
}

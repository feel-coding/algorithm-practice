#include <iostream>
using namespace std;

int main() {
	int arr[105];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x, y;
	cin >> x >> y;
	int index;
	if (x - y < 0) index = x - y + n;
	else index = x - y;
	cout << arr[index];
	return 0;
}

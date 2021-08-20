#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int index = 0;
	int arr[15];
	while (n > 0) {
		arr[index++] = n % 2;
		n /= 2;
	}
	for (int i = index - 1; i >= 0; i--) {
		cout << arr[i];
	}
	return 0;
}

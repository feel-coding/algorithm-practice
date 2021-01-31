#include <iostream>
using namespace std;

int main() {
	int arr[8] = { 1, 2, 3, 4, 5, 4, 3, 2 };
	int n;
	cin >> n;
	cout << arr[(n - 1) % 8];
	return 0;
}

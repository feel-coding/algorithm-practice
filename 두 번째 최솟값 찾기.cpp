#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int temp[9];

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		temp[i] = arr[i];
	}
	sort(arr, arr + 9);
	cout << arr[1] << endl;
	for (int i = 0; i < 9; i++) {
		if (temp[i] == arr[1]) {
			cout << i + 1;
			break;
		}
	}
	return 0;
}

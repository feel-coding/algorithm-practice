#include <iostream>
using namespace std;

int arr[1005] = { 0 };
int temp[1005] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		temp[i] = arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (temp[i] == 1) {
			if (temp[i - 1] == 0) arr[i - 1] = 1;
			if (temp[i + 1] == 0) arr[i + 1] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}

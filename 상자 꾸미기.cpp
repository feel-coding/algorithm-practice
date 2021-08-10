#include <iostream>
using namespace std;

int main() {
	int arr[1005] = { 0 };
	int n;
	cin >> n;
	int color;
	for (int i = 0; i < n; i++) {
		cin >> color;
		arr[color]++;
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] >= 2) result += 2;
		else result += arr[i];
	}
	if (result >= 6) cout << "YES";
	else cout << "NO";
	return 0;
}

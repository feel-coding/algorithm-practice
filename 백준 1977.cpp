#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int arr[100];
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < 100; i++) {
		arr[i] = (i + 1) * (i + 1);
	}
	int count = 0;
	long long sum = 0;
	int minNum;
	for (int i = 0; i < 100; i++) {
		if (arr[i] >= m && arr[i] <= n) {
			count++;
			sum += arr[i];
			if (count == 1) {
				minNum = arr[i];
			}
		}
	}
	if (count == 0) cout << -1;
	else {
		cout << sum << endl;
		cout << minNum;
	}
	return 0;
}
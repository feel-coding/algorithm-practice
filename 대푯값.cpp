#include <iostream>
using namespace std;

int main() {
	int arr[1001] = { 0 };
	int n;
	int sum = 0;
	int maxNum;
	int maxCnt = 0;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		sum += n;
		arr[n]++;
	}
	for (int i = 10; i <= 1000; i += 10) {
		if (arr[i] > maxCnt) {
			maxCnt = arr[i];
			maxNum = i;
		}
	}
	cout << sum / 10 << endl;
	cout << maxNum;
	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	int temp;
	int maxSum = 0;
	int winnerNum;
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> temp;
			sum += temp;
		}
		if (sum > maxSum) {
			maxSum = sum;
			winnerNum = i;
		}
	}
	cout << winnerNum << " " << maxSum;
	return 0;
}
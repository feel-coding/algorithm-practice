#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long aCount = 1;
	long long bCount = 0;
	for (int i = 0; i < n; i++) {
		int tempA = aCount;
		int temkpB = bCount;
		aCount = bCount;
		bCount += tempA;
	}
	cout << aCount << " " << bCount;
	return 0;
}

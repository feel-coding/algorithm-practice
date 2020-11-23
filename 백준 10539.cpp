#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int temp;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		cout << temp * (i + 1) - sum << " ";
		sum += (temp * (i + 1) - sum);
	}
	return 0;
}
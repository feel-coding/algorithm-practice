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
	long long a, b;
	cin >> a >> b;
	cout << (a + b) * (a - b);
	return 0;
}
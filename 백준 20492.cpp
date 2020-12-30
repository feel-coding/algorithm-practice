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
	cout << fixed << (int)(n * 0.78) << " " << (int)(n * 0.8 + n * 0.2 * 0.78);
	return 0;
}
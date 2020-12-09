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
	string a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << "Distances: ";
		for (int j = 0; j < a.size(); j++) {
			cout << (b[j] - a[j] < 0 ? b[j] - a[j] + 26 : b[j] - a[j]) << " ";
		}
		cout << '\n';
	}
	return 0;
}
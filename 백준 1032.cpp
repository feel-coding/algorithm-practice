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
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < v[0].size(); i++) {
		bool isEqual = true;
		char alphabet = v[0][i];
		for (int j = 1; j < n; j++) {
			if (v[j][i] != alphabet) {
				isEqual = false;
				break;
			}
		}
		if (isEqual) {
			cout << v[0][i];
		}
		else {
			cout << "?";
		}
	}
	return 0;
}
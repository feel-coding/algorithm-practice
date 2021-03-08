#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, p, c;
	string name;
	cin >> n;
	for (int t = 0; t < n; t++) {
		int maxC = 0;
		string maxName;
		cin >> p;
		for (int i = 0; i < p; i++) {
			cin >> c >> name;
			if (c > maxC) {
				maxC = c;
				maxName = name;
			}
		}
		cout << maxName << '\n';
	}
	return 0;
}
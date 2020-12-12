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
	vector<int> v(20);
	for (int i = 0; i < 20; i++) {
		v[i] = i + 1;
	}
	int start, end;
	for (int i = 0; i < 10; i++) {
		cin >> start >> end;
		vector<int> temp;
		for (int j = end - 1; j >= start - 1; j--) {
			temp.push_back(v[j]);
		}
		int index = start - 1;
		for (int j = 0; j < temp.size(); j++) {
			v[index++] = temp[j];
		}
	}
	for (int i = 0; i < 20; i++) {
		cout << v[i] << " ";
	}
	return 0;
}
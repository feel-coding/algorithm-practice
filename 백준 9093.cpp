#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int index = 0;
		int tempIndex;
		vector<bool> visited(s.size(), false);
		while (true) {
			if (index > s.size())
				break;
			//cout << "index´Â " << index << endl;
			if (index == s.size() || s[index] == ' ') {
				tempIndex = index;
				if (index < s.size()) {
					visited[index] = true;
				}
				while (true) {
					if (index - 1 < 0 || visited[index - 1])
						break;
					cout << s[--index];
					visited[index] = true;
				}
				cout << ' ';
				index = tempIndex;
			}
			index++;
		}
		cout << '\n';
	}
	return 0;
}
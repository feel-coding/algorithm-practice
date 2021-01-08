#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n;
	for (int t = 0; t < n; t++) {
		cin >> s;
		vector<pair<char, int>> v;
		v.push_back(make_pair(s[0], 1));
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == v[v.size() - 1].first) {
				v[v.size() - 1].second++;
			}
			else {
				v.push_back(make_pair(s[i], 1));
			}
		}
		int i = 0;
		while (i < v.size()) {
			if (v[i].first == '1') {
				if (v[i].second == 1 && i + 1 < v.size() && v[i + 1].first == '0' && v[i + 1].second >= 2 && i + 2 < v.size() && v[i + 2].first == '1') {
					i += 3;
				}
				else {
					break;
				}
			}
			else {
				if (v[i].second == 1 && i + 1 < v.size() && v[i + 1].first == '1' && v[i + 1].second >= 1) {
					if (v[i + 1].second > 1) {
						v.insert(v.begin() + i + 2, make_pair(v[i + 1].first, v[i + 1].second - 1));
					}
					i += 2;
				}
				else {
					if (i - 1 >= 0 && v[i - 1].first == '1' && v[i - 1].second > 1) {
						v.insert(v.begin() + i, make_pair('1', 1));
					}
					else {
						break;
					}
				}
			}
		}
		cout << (i == v.size() ? "YES\n" : "NO\n");
	}
	return 0;
}

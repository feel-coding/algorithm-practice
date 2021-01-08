#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, num;
	cin >> n;
	string s;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_front") {
			cin >> num;
			v.insert(v.begin(), num);
		}
		else if (s == "push_back") {
			cin >> num;
			v.push_back(num);
		}
		else if (s == "pop_front") {
			if (v.size() > 0) {
				cout << v[0] << '\n';
				v.erase(v.begin());
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "pop_back") {
			if (v.size() > 0) {
				cout << v[v.size() - 1] << '\n';
				v.pop_back();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "size") {
			cout << v.size() << '\n';
		}
		else if (s == "empty") {
			cout << v.empty() << '\n';
		}
		else if (s == "front") {
			if (v.size() > 0) {
				cout << v[0] << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (s == "back") {
			if (v.size() > 0) {
				cout << v[v.size() - 1] << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	string name;
	vector<string> answer;
	for (int i = 0; i < m; i++) {
		cin >> name;
		if (binary_search(v.begin(), v.end(), name)) {
			answer.push_back(name);
		}
	}
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}

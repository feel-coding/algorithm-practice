#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int r, n;
vector<char> v;

void select(vector<bool> visited, vector<char> result, int num) {
	if (num == r) {
		int vowelCount = 0;
		int consonantCount = 0;	
		for (int i = 0; i < r; i++) {
			if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u') 
				vowelCount++;
			else 
				consonantCount++;
		}
		if (!(vowelCount >= 1 && consonantCount >= 2)) {
			return;
		}
		for (int i = 0; i < r; i++) {
			cout << result[i];
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (num == 0) {
				visited[i] = true;
				result[num] = v[i];
				select(visited, result, num + 1);
				visited[i] = false;
			}
			else {
				if (result[num - 1] < v[i]) {
					visited[i] = true;
					result[num] = v[i];
					select(visited, result, num + 1);
					visited[i] = false;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> r >> n;
	for (int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	vector<char> result(r);
	vector<bool> visited(n);
	select(visited, result, 0);
	return 0;
}
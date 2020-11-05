#include <iostream> 
#include <vector> 
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

int cnt = 0;
set<int> st;

void combination(vector<bool> visited, vector<int> result, int n, int k, int num, int* arr) {
	if (num == k) {
	
		do {
			string str = "";
			for (int i = 0; i < k; i++) {
				str += (result[i] + '0');
			}
			int number = stoi(str);
			//st.insert(number);
			bool flag = true;
			if (number % 2 == 1) {
				for (int i = 2; i <= sqrt(number); i++) {
					if (number % i == 0) {
						flag = false;
						break;
					}
				}
			}
			else {
				flag = false;
			}
			if (number == 1 || number == 0) flag = false;
			if (number == 2) flag = true;
			if (flag) {
				//cnt++;
				st.insert(number);
			}

		} while (next_permutation(result.begin(), result.end()));
		return;
	}
	for (int i = 0; i < n; i++) {
		if (num == 0) {
			if (!visited[i]) {
				visited[i] = true;
				result[num] = arr[i];
				combination(visited, result, n, k, num + 1, arr);
				visited[i] = false;
			}
		}
		else {
			if (!visited[i] && result[num - 1] <= arr[i]) {
				visited[i] = true;
				result[num] = arr[i];
				combination(visited, result, n, k, num + 1, arr);
				visited[i] = false;
			}
		}
	}
}

int main() {
	int c;
	cin >> c;
	for (int t = 0; t < c; t++) {
		st.clear();
		string s;
		cin >> s;
		int* arr = new int[7];
		for (int i = 0; i < s.size(); i++) {
			arr[i] = s[i] - '0';
		}
		sort(arr, arr + s.size());
		for (int i = 1; i <= s.size(); i++) {
			vector<bool> visited(s.size());
			vector<int> result(i);
			combination(visited, result, s.size(), i, 0, arr);
		}
		cout << st.size() << '\n';
	}

	return 0;
}
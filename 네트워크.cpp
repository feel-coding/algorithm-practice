#include <string>
#include <vector>
#include <stack>

using namespace std;

bool visited[205];
int cnt = 0;

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			cnt++;
			stack<int> s;
			s.push(i);
			while (!s.empty()) {
				int cur = s.top();
				s.pop();
				if (!visited[cur]) {
					visited[cur] = true;
					for (int j = 0; j < n; j++) {
						if (!visited[j] && computers[cur][j] == 1) {
							s.push(j);
						}
					}
				}
			}
		}
	}
	return cnt;
}
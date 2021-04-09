#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[55];

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < words.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < words[i].size(); j++) {
			if (words[i][j] != begin[j]) {
				cnt++;
			}
		}
		if (cnt == 1) {
			q.push(make_pair(i, 1));
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (words[cur.first] == target) {
			answer = cur.second;
			break;
		}
		if (!visited[cur.first]) {
			visited[cur.first] = true;
			for (int i = 0; i < words.size(); i++) {
				if (visited[i]) continue;
				int cnt = 0;
				for (int j = 0; j < words[i].size(); j++) {
					if (words[i][j] != words[cur.first][j]) {
						cnt++;
					}
				}
				if (cnt == 1) {
					q.push(make_pair(i, cur.second + 1));
				}
			}
		}

	}
	return answer;
}

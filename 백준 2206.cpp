#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<string> map;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map.push_back(s);
	}

	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(0, 0, 0, 1)); //행, 열, 벽 부쉈는지 아닌지, 현재까지 몇 칸 거쳐왔는지
	vector<vector<vector<bool>>> visited(2, vector<vector<bool>>(n));
	for (int i = 0; i < 2; i++) {
		for(int j = 0; j < n; j++)
			visited[i][j] = vector<bool>(m);
	}
	vector<int> distance;
	while (!q.empty()) {
		tuple<int, int, int, int> cur = q.front();
		q.pop();
		if (!visited[get<2>(cur)][get<0>(cur)][get<1>(cur)]) {
			if(map[get<0>(cur)][get<1>(cur)] == '0')
				visited[get<2>(cur)][get<0>(cur)][get<1>(cur)] = true;
			if (get<0>(cur) == n - 1 && get<1>(cur) == m - 1) {
				distance.push_back(get<3>(cur));
			}
			else {
				if (get<0>(cur) - 1 >= 0 && map[get<0>(cur) - 1][get<1>(cur)] == '0' && !visited[get<2>(cur)][get<0>(cur) - 1][get<1>(cur)]) {
					q.push(make_tuple(get<0>(cur) - 1, get<1>(cur), get<2>(cur), get<3>(cur) + 1));
				}
				if (get<0>(cur) + 1 < n && map[get<0>(cur) + 1][get<1>(cur)] == '0' && !visited[get<2>(cur)][get<0>(cur) + 1][get<1>(cur)]) {
					q.push(make_tuple(get<0>(cur) + 1, get<1>(cur), get<2>(cur), get<3>(cur) + 1));
				}
				if (get<1>(cur) - 1 >= 0 && map[get<0>(cur)][get<1>(cur) - 1] == '0' && !visited[get<2>(cur)][get<0>(cur)][get<1>(cur) - 1]) {
					q.push(make_tuple(get<0>(cur), get<1>(cur) - 1, get<2>(cur), get<3>(cur) + 1));
				}
				if (get<1>(cur) + 1 < m && map[get<0>(cur)][get<1>(cur) + 1] == '0' && !visited[get<2>(cur)][get<0>(cur)][get<1>(cur) + 1]) {
					q.push(make_tuple(get<0>(cur), get<1>(cur) + 1, get<2>(cur), get<3>(cur) + 1));
				}


				if (get<0>(cur) - 1 >= 0 && map[get<0>(cur) - 1][get<1>(cur)] == '1' && get<2>(cur) == 0 && !visited[get<2>(cur)][get<0>(cur) - 1][get<1>(cur)]) {
					q.push(make_tuple(get<0>(cur) - 1, get<1>(cur), get<2>(cur) + 1, get<3>(cur) + 1));
				}
				if (get<0>(cur) + 1 < n && map[get<0>(cur) + 1][get<1>(cur)] == '1' && get<2>(cur) == 0 && !visited[get<2>(cur)][get<0>(cur) + 1][get<1>(cur)]) {
					q.push(make_tuple(get<0>(cur) + 1, get<1>(cur), get<2>(cur) + 1, get<3>(cur) + 1));
				}
				if (get<1>(cur) - 1 >= 0 && map[get<0>(cur)][get<1>(cur) - 1] == '1' && get<2>(cur) == 0 && !visited[get<2>(cur)][get<0>(cur)][get<1>(cur) - 1]) {
					q.push(make_tuple(get<0>(cur), get<1>(cur) - 1, get<2>(cur) + 1, get<3>(cur) + 1));
				}
				if (get<1>(cur) + 1 < m && map[get<0>(cur)][get<1>(cur) + 1] == '1' && get<2>(cur) == 0 && !visited[get<2>(cur)][get<0>(cur)][get<1>(cur) + 1]) {
					q.push(make_tuple(get<0>(cur), get<1>(cur) + 1, get<2>(cur) + 1, get<3>(cur) + 1));
				}
			}
		}
	}
	if (distance.empty()) cout << -1;
	else {
		int minDist = 1000001;
		for (int i = 0; i < distance.size(); i++) {
			if (distance[i] < minDist)
				minDist = distance[i];
		}
		cout << minDist;
	}
	return 0;
}
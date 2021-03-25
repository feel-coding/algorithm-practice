#include <iostream>
#include <vector>
using namespace std;

struct Car {
	int x;
	int y;
	int direction;
	bool exist;
};

Car cars[1005];
int carCount[4005][4005];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	int testCase, n;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		int crushCount = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cars[i].x >> cars[i].y >> cars[i].direction;
			cars[i].x *= 2;
			cars[i].x += 2000;
			cars[i].y *= 2;
			cars[i].y += 2000;
			cars[i].exist = true;
			carCount[cars[i].x][cars[i].y]++;
		}
		int distance = 1;
		int cnt = 0;
		while (cnt < n) {
			vector<pair<int, int>> v;
			for (int i = 0; i < n; i++) { // ���� �ȿ� �����ϴ� ��� ������ 0.5�� �̵���Ų��
				if (!cars[i].exist) continue;
				int direction = cars[i].direction;
				carCount[cars[i].x][cars[i].y]--;
				int nx = cars[i].x + dx[direction];
				int ny = cars[i].y + dy[direction];
				if (nx < 0 || ny < 0 || nx > 4000 || ny > 4000) { // ������ �����
					cars[i].exist = false; // �������
					cnt++;
				}
				else {
					carCount[nx][ny]++;
					cars[i].x = nx;
					cars[i].y = ny;
					if (carCount[nx][ny] == 2) {
						crushCount++;
						v.push_back(make_pair(nx, ny));
					}
				}
			}
			for (int i = 0; i < n; i++) { // ���� ���� ��ġ�� �ִ� ���� ������ �浹�ߴٴ� ��
				if (carCount[cars[i].x][cars[i].y] > 1) {
					cars[i].exist = false;
					cnt++;
				}
			}
			for (int i = 0; i < v.size(); i++) {
				carCount[v[i].first][v[i].second] = 0;
			}
		}
		cout << "#" << t << " " << crushCount << endl;
	}
	return 0;
}

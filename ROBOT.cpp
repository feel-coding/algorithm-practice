#include <iostream>
#include <queue>
#include <string>
using namespace std;

int arr[105][105];
int visited[105][105][4];
int n, m;   //µ¿,¼­,³²,ºÏ
string direction[4] = { "µ¿", "¼­", "³²", "ºÏ" };
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int leftDirection[4] = { 3, 2, 0, 1 };
int rightDirection[4] = { 2, 3, 1, 0 };
int minCommandCnt = 10000000;

struct location {
	int row;
	int col;
	int direction;
	int commandCnt;
};

int main() {
	int startRow, startCol, startDirection;
	int endRow, endCol, endDirection;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> startRow >> startCol >> startDirection >> endRow >> endCol >> endDirection;
	startDirection--;
	endDirection--;
	queue<location> q;
	q.push({ startRow, startCol, startDirection, 0 });
	while (!q.empty()) {
		location cur = q.front();
		q.pop();
		if (cur.row == endRow && cur.col == endCol && cur.direction == endDirection) {
			cout << cur.commandCnt;
			break;
		}
		int curRow = cur.row;
		int curCol = cur.col;
		int curDir = cur.direction;
		if (!visited[cur.row][cur.col][cur.direction]) {
			visited[cur.row][cur.col][cur.direction] = true;
			q.push({ cur.row, cur.col, leftDirection[cur.direction], cur.commandCnt + 1 });
			q.push({ cur.row, cur.col, rightDirection[cur.direction], cur.commandCnt + 1 });
			int nr = cur.row + dr[cur.direction];
			int nc = cur.col + dc[cur.direction];
			if (nr < 1 || nr > n || nc < 1 || nc > m || arr[nr][nc] == 1) continue;
			q.push({ nr, nc, cur.direction, cur.commandCnt + 1 });
			nr = cur.row + dr[cur.direction] * 2;
			nc = cur.col + dc[cur.direction] * 2;
			if (nr < 1 || nr > n || nc < 1 || nc > m || arr[nr][nc] == 1) continue;
			q.push({ nr, nc, cur.direction, cur.commandCnt + 1 });
			nr = cur.row + dr[cur.direction] * 3;
			nc = cur.col + dc[cur.direction] * 3;

			if (nr < 1 || nr > n || nc < 1 || nc > m || arr[nr][nc] == 1) continue;
			q.push({ nr, nc, cur.direction, cur.commandCnt + 1 });
		}
	}
	return 0;
}

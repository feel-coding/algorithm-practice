#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	pair<int, int> blue;
	pair<int, int> red;
	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'B') {
				blue = make_pair(i, j);
				v[i][j] = '.';
			}
			else if (v[i][j] == 'R') {
				red = make_pair(i, j);
				v[i][j] = '.';
			}
		}
	}
	map<pair<pair<int, int>, pair<int, int>>, int> visited; // »¡, ÆÄ
	queue<tuple<pair<int, int>, pair<int, int>, int>> q;
	q.push(make_tuple(red, blue, 0));
	int answer = -1;
	while (!q.empty()) {
		tuple<pair<int, int>, pair<int, int>, int> cur = q.front();
		q.pop();
		int redRow = get<0>(cur).first;
		int redCol = get<0>(cur).second;
		int blueRow = get<1>(cur).first;
		int blueCol = get<1>(cur).second;
		int cnt = get<2>(cur);
		int tempRedRow;
		int tempRedCol;
		int tempBlueRow;
		int tempBlueCol;
		int flag;
		if (cnt < 10 && !visited[make_pair(get<0>(cur), get<1>(cur))]) {
			visited[make_pair(get<0>(cur), get<1>(cur))] = true;
			// À§
			tempRedRow = redRow;
			tempBlueRow = blueRow;
			flag = true;
			if (redCol == blueCol) {
				if (redRow > blueRow) {
					while (tempBlueRow >= 1) {
						char next = v[tempBlueRow - 1][blueCol];
						if (next == 'O') {
							flag = false;
							tempBlueRow--;
							break;
						}
						else if (next == '.') {
							tempBlueRow--;
						}
						else {
							break;
						}
					}
					while (tempRedRow >= 1) {
						char next = v[tempRedRow - 1][redCol];
						if (next != 'O' && tempRedRow - 1 == tempBlueRow)
							break;
						if (next == 'O') {
							answer = cnt + 1;
							tempRedRow--;
							break;
						}
						else if (next == '.') {
							tempRedRow--;
						}
						else {
							break;
						}
					}
				}
				else {
					while (tempRedRow >= 1) {
						char next = v[tempRedRow - 1][redCol];
						if (next == 'O') {
							answer = cnt + 1;
							tempRedRow--;
							break;
						}
						else if (next == '.') {
							tempRedRow--;
						}
						else {
							break;
						}
					}
					while (tempBlueRow >= 1) {
						char next = v[tempBlueRow - 1][blueCol];
						if (next != 'O' && tempBlueRow - 1 == tempRedRow)
							break;
						if (next == 'O') {
							flag = false;
							tempBlueRow--;
							break;
						}
						else if (next == '.') {
							tempBlueRow--;
						}
						else {
							break;
						}
					}
				}
				if (answer != -1) {
					if (!flag)
						answer = -1;
					if (answer != -1)
						break;
				}
				if (tempRedRow == redRow && tempBlueRow == blueRow)
					flag = false;
				if (flag) {
					q.push(make_tuple(make_pair(tempRedRow, redCol), make_pair(tempBlueRow, blueCol), cnt + 1));
				}
			}
			else {
				while (tempRedRow >= 1) {
					char next = v[tempRedRow - 1][redCol];
					if (next == 'O') {
						answer = cnt + 1;
						tempRedRow--;
						break;
					}
					else if (next == '.') {
						tempRedRow--;
					}
					else {
						break;
					}
				}
				while (tempBlueRow >= 1) {
					char next = v[tempBlueRow - 1][blueCol];
					if (next == 'O') {
						flag = false;
						tempBlueRow--;
						break;
					}
					else if (next == '.') {
						tempBlueRow--;
					}
					else {
						break;
					}
				}
			}
			if (answer != -1) {
				break;
			}
			if (tempRedRow == redRow && tempBlueRow == blueRow)
				flag = false;
			if (flag) {
				q.push(make_tuple(make_pair(tempRedRow, redCol), make_pair(tempBlueRow, blueCol), cnt + 1));
			}
			// ¾Æ·¡
			tempRedRow = redRow;
			tempBlueRow = blueRow;
			flag = true;
			if (redCol == blueCol) {
				if (redRow < blueRow) {
					while (tempBlueRow < n - 1) {
						char next = v[tempBlueRow + 1][blueCol];
						if (next == 'O') {
							flag = false;
							tempBlueRow++;
							break;
						}
						else if (next == '.') {
							tempBlueRow++;
						}
						else {
							break;
						}
					}
					while (tempRedRow < n - 1) {
						char next = v[tempRedRow + 1][redCol];
						if (next != 'O' && tempRedRow + 1 == tempBlueRow)
							break;
						if (next == 'O') {
							answer = cnt + 1;
							tempRedRow++;
							break;
						}
						else if (next == '.') {
							tempRedRow++;
						}
						else {
							break;
						}
					}
				}
				else {
					while (tempRedRow < n - 1) {
						char next = v[tempRedRow + 1][redCol];
						if (next == 'O') {
							answer = cnt + 1;
							tempRedRow++;
							break;
						}
						else if (next == '.') {
							tempRedRow++;
						}
						else {
							break;
						}
					}
					while (tempBlueRow < n - 1) {
						char next = v[tempBlueRow + 1][blueCol];
						if (next != 'O' && tempBlueRow + 1 == tempRedRow)
							break;
						if (next == 'O') {
							flag = false;
							tempBlueRow++;
							break;
						}
						else if (next == '.') {
							tempBlueRow++;
						}
						else {
							break;
						}
					}
				}
				if (answer != -1) {
					if (!flag)
						answer = -1;
					if (answer != -1)
						break;
				}
				if (tempRedRow == redRow && tempBlueRow == blueRow)
					flag = false;
				if (flag) {
					q.push(make_tuple(make_pair(tempRedRow, redCol), make_pair(tempBlueRow, blueCol), cnt + 1));
				}
			}
			else {
				while (tempRedRow < n - 1) {
					char next = v[tempRedRow + 1][redCol];
					if (next == 'O') {
						answer = cnt + 1;
						tempRedRow++;
						break;
					}
					else if (next == '.') {
						tempRedRow++;
					}
					else {
						break;
					}
				}
				while (tempBlueRow < n - 1) {
					char next = v[tempBlueRow + 1][blueCol];
					if (next == 'O') {
						flag = false;
						tempBlueRow++;
						break;
					}
					else if (next == '.') {
						tempBlueRow++;
					}
					else {
						break;
					}
				}
			}
			if (tempRedRow == redRow && tempBlueRow == blueRow)
				flag = false;
			if (answer != -1) {
				break;
			}
			if (flag) {
				q.push(make_tuple(make_pair(tempRedRow, redCol), make_pair(tempBlueRow, blueCol), cnt + 1));
			}
			// ¿ÞÂÊ
			tempRedCol = redCol;
			tempBlueCol = blueCol;
			flag = true;
			if (redRow == blueRow) {
				if (redCol > blueCol) {
					while (tempBlueCol >= 1) {
						char next = v[blueRow][tempBlueCol - 1];
						if (next == 'O') {
							flag = false;
							tempBlueCol--;
							break;
						}
						else if (next == '.') {
							tempBlueCol--;
						}
						else {
							break;
						}
					}
					while (tempRedCol >= 1) {
						char next = v[redRow][tempRedCol - 1];
						if (next != 'O' && tempRedCol - 1 == tempBlueCol)
							break;
						if (next == 'O') {
							answer = cnt + 1;
							tempRedCol--;
							break;
						}
						else if (next == '.') {
							tempRedCol--;
						}
						else {
							break;
						}
					}
				}
				else {
					while (tempRedCol >= 1) {
						char next = v[redRow][tempRedCol - 1];
						if (next == 'O') {
							answer = cnt + 1;
							tempRedCol--;
							break;
						}
						else if (next == '.') {
							tempRedCol--;
						}
						else {
							break;
						}
					}
					while (tempBlueCol >= 1) {
						char next = v[blueRow][tempBlueCol - 1];
						if (next != 'O' && tempBlueCol - 1 == tempRedCol)
							break;
						if (next == 'O') {
							flag = false;
							tempBlueCol--;
							break;
						}
						else if (next == '.') {
							tempBlueCol--;
						}
						else {
							break;
						}
					}
				}
				if (answer != -1) {
					if (!flag)
						answer = -1;
					if (answer != -1)
						break;
				}
				if (tempRedCol == redCol && tempBlueCol == blueCol)
					flag = false;
				if (flag) {
					q.push(make_tuple(make_pair(redRow, tempRedCol), make_pair(blueRow, tempBlueCol), cnt + 1));
				}
			}
			else {
				while (tempRedCol >= 1) {
					char next = v[redRow][tempRedCol - 1];
					if (next == 'O') {
						answer = cnt + 1;
						tempRedCol--;
						break;
					}
					else if (next == '.') {
						tempRedCol--;
					}
					else {
						break;
					}
				}
				while (tempBlueCol >= 1) {
					char next = v[blueRow][tempBlueCol - 1];
					if (next == 'O') {
						flag = false;
						tempBlueCol--;
						break;
					}
					else if (next == '.') {
						tempBlueCol--;
					}
					else {
						break;
					}
				}
			}
			if (answer != -1) {
				break;
			}
			if (tempRedCol == redCol && tempBlueCol == blueCol)
				flag = false;
			if (flag) {
				q.push(make_tuple(make_pair(redRow, tempRedCol), make_pair(blueRow, tempBlueCol), cnt + 1));
			}
			// ¿À¸¥ÂÊ
			tempRedCol = redCol;
			tempBlueCol = blueCol;
			flag = true;
			if (redRow == blueRow) {
				if (redCol < blueCol) {
					while (tempBlueCol < m - 1) {
						char next = v[blueRow][tempBlueCol + 1];
						if (next == 'O') {
							flag = false;
							tempBlueCol++;
							break;
						}
						else if (next == '.') {
							tempBlueCol++;
						}
						else {
							break;
						}
					}
					while (tempRedCol < m - 1) {
						char next = v[redRow][tempRedCol + 1];
						if (next != 'O' && tempRedCol + 1 == tempBlueCol)
							break;
						if (next == 'O') {
							answer = cnt + 1;
							tempRedCol++;
							break;
						}
						else if (next == '.') {
							tempRedCol++;
						}
						else {
							break;
						}
					}
				}
				else {
					while (tempRedCol < m - 1) {
						char next = v[redRow][tempRedCol + 1];
						if (next == 'O') {
							tempRedCol++;
							answer = cnt + 1;
							break;
						}
						else if (next == '.') {
							tempRedCol++;
						}
						else {
							break;
						}
					}
					while (tempBlueCol < m - 1) {
						char next = v[blueRow][tempBlueCol + 1];
						if (next != 'O' && tempBlueCol + 1 == tempRedCol)
							break;
						if (next == 'O') {
							flag = false;
							tempBlueCol++;
							break;
						}
						else if (next == '.') {
							tempBlueCol++;
						}
						else {
							break;
						}
					}
				}
				if (answer != -1) {
					if (!flag)
						answer = -1;
					if (answer != -1)
						break;
				}
				if (tempRedCol == redCol && tempBlueCol == blueCol)
					flag = false;
				if (flag) {
					q.push(make_tuple(make_pair(redRow, tempRedCol), make_pair(blueRow, tempBlueCol), cnt + 1));
				}
			}
			else {
				while (tempRedCol < m - 1) {
					char next = v[redRow][tempRedCol + 1];
					if (next == 'O') {
						answer = cnt + 1;
						tempRedCol++;
						break;
					}
					else if (next == '.') {
						tempRedCol++;
					}
					else {
						break;
					}
				}
				while (tempBlueCol >= 1) {
					char next = v[blueRow][tempBlueCol + 1];
					if (next == 'O') {
						flag = false;
						tempBlueCol++;
						break;
					}
					else if (next == '.') {
						tempBlueCol++;
					}
					else {
						break;
					}
				}
			}
			if (answer != -1) {
				break;
			}
			if (tempRedCol == redCol && tempBlueCol == blueCol)
				flag = false;
			if (flag) {
				q.push(make_tuple(make_pair(redRow, tempRedCol), make_pair(blueRow, tempBlueCol), cnt + 1));
			}
		}
	}
	cout << answer;
	return 0;
}

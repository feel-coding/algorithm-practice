#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dice[6] = { 0 };
vector<vector<int>> map;

void toNorth(int& nowRow, int& nowCol, int& floorIndex, int& ceilingIndex, int& westIndex, int& eastIndex, int& northIndex, int& southIndex) {
	if (nowRow - 1 < 0) return;
	int temp = floorIndex;
	floorIndex = northIndex;
	northIndex = ceilingIndex;
	ceilingIndex = southIndex;
	southIndex = temp;
	nowRow--;
	if (map[nowRow][nowCol] == 0) {
		map[nowRow][nowCol] = dice[floorIndex];
	}
	else {
		dice[floorIndex] = map[nowRow][nowCol];
		map[nowRow][nowCol] = 0;
	}
	cout << dice[ceilingIndex] << '\n';
}
void toSouth(int& nowRow, int& nowCol, int& floorIndex, int& ceilingIndex, int& westIndex, int& eastIndex, int& northIndex, int& southIndex) {
	if (nowRow + 1 >= n) return;
	int temp = floorIndex;
	floorIndex = southIndex;
	southIndex = ceilingIndex;
	ceilingIndex = northIndex;
	northIndex = temp;
	nowRow++;
	if (map[nowRow][nowCol] == 0) {
		map[nowRow][nowCol] = dice[floorIndex];
	}
	else {
		dice[floorIndex] = map[nowRow][nowCol];
		map[nowRow][nowCol] = 0;
	}
	cout << dice[ceilingIndex] << '\n';
}
void toEast(int& nowRow, int& nowCol, int& floorIndex, int& ceilingIndex, int& westIndex, int& eastIndex, int& northIndex, int& southIndex) {
	if (nowCol + 1 >= m) return;
	int temp = westIndex;
	westIndex = floorIndex;
	floorIndex = eastIndex;
	eastIndex = ceilingIndex;
	ceilingIndex = temp;
	nowCol++;
	if (map[nowRow][nowCol] == 0) {
		map[nowRow][nowCol] = dice[floorIndex];
	}
	else {
		dice[floorIndex] = map[nowRow][nowCol];
		map[nowRow][nowCol] = 0;
	}
	cout << dice[ceilingIndex] << '\n';
}
void toWest(int& nowRow, int& nowCol, int& floorIndex, int& ceilingIndex, int& westIndex, int& eastIndex, int& northIndex, int& southIndex) {
	if (nowCol - 1 < 0) return;
	int temp = floorIndex;
	floorIndex = westIndex;
	westIndex = ceilingIndex;
	ceilingIndex = eastIndex;
	eastIndex = temp;
	nowCol--;
	if (map[nowRow][nowCol] == 0) {
		map[nowRow][nowCol] = dice[floorIndex];
	}
	else {
		dice[floorIndex] = map[nowRow][nowCol];
		map[nowRow][nowCol] = 0;
	}
	cout << dice[ceilingIndex] << '\n';
}


int main() {
	int nowCol, nowRow, k;
	cin >> n >> m >> nowRow >> nowCol >> k;
	map = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int floorIndex = 0;
	int eastIndex = 1;
	int ceilingIndex = 2;
	int westIndex = 3;
	int northIndex = 4;
	int southIndex = 5;
	for (int i = 0; i < k; i++) {
		int direction;
		cin >> direction;
		switch (direction) {
		case 1:
			toEast(nowRow, nowCol, floorIndex, ceilingIndex, westIndex, eastIndex, northIndex, southIndex);
			break;
		case 2:
			toWest(nowRow, nowCol, floorIndex, ceilingIndex, westIndex, eastIndex, northIndex, southIndex);
			break;
		case 3:
			toNorth(nowRow, nowCol, floorIndex, ceilingIndex, westIndex, eastIndex, northIndex, southIndex);
			break;
		case 4:
			toSouth(nowRow, nowCol, floorIndex, ceilingIndex, westIndex, eastIndex, northIndex, southIndex);
			break;
		}
	}
	return 0;
}
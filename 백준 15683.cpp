#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int numOfCctv;
vector<char> cctv[6]; //1~5만 씀
int minSquare = 64;
vector<pair<int, int>> cctvLocation;
vector<int> cctvInfo;
vector<vector<int>> v;
int n, m;

void spread(vector<vector<int>>& office, int row, int col, char c) {
	if (c == 'e') {
		while (true) {
			if (col + 1 < m && office[row][++col] != 6) {
				if (office[row][col] != 0)
					continue;
				office[row][col] = -1;
			}
			else break;
		}
	}
	else if (c == 'w') {
		while (true) {
			if (col - 1 >= 0 && office[row][--col] != 6) {
				if (office[row][col] != 0)
					continue;
				office[row][col] = -1;
			}
			else break;
		}
	}
	else if (c == 's') {
		while (true) {
			if (row + 1 < n && office[++row][col] != 6) {
				if (office[row][col] != 0)
					continue;
				office[row][col] = -1;
			}
			else break;
		}
	}
	else if (c == 'n') {
		while (true) {
			if (row - 1 >= 0 && office[--row][col] != 6) {
				if (office[row][col] != 0)
					continue;
				office[row][col] = -1;
			}
			else break;
		}
	}
}

int getArea(vector<char> result) {
	vector<vector<int>> office(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			office[i][j] = v[i][j];
		}
	}
	for (int i = 0; i < result.size(); i++) {
		int row = cctvLocation[i].first;
		int col = cctvLocation[i].second;
		if (cctvInfo[i] == 1) {
			spread(office, row, col, result[i]);
		}
		else if (cctvInfo[i] == 2) {
			if (result[i] == 'h') {
				spread(office, row, col, 'e');
				spread(office, row, col, 'w');
			}
			else if (result[i] == 'v') {
				spread(office, row, col, 's');
				spread(office, row, col, 'n');
			}
		}
		else if (cctvInfo[i] == 3) {
			if (result[i] == 'e') {
				spread(office, row, col, 'e');
				spread(office, row, col, 's');
			}
			else if (result[i] == 'w') {
				spread(office, row, col, 'w');
				spread(office, row, col, 'n');
			}
			else if (result[i] == 's') {
				spread(office, row, col, 's');
				spread(office, row, col, 'w');
			}
			else if (result[i] == 'n') {
				spread(office, row, col, 'n');
				spread(office, row, col, 'e');
			}
		}
		else if (cctvInfo[i] == 4) {
			if (result[i] == 'e') {
				spread(office, row, col, 'n');
				spread(office, row, col, 'e');
				spread(office, row, col, 's');
			}
			else if (result[i] == 'w') {
				spread(office, row, col, 's');
				spread(office, row, col, 'w');
				spread(office, row, col, 'n');
			}
			else if (result[i] == 's') {
				spread(office, row, col, 'e');
				spread(office, row, col, 's');
				spread(office, row, col, 'w');
			}
			else if (result[i] == 'n') {
				spread(office, row, col, 'w');
				spread(office, row, col, 'n');
				spread(office, row, col, 'e');
			}
		}
		else if (cctvInfo[i] == 5) {
			spread(office, row, col, 'w');
			spread(office, row, col, 'n');
			spread(office, row, col, 'e');
			spread(office, row, col, 's');
		}
	}
	/*cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(3) << office[i][j];
		}
		cout << endl;
	}*/
	int countZero = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (office[i][j] == 0)
				countZero++;
		}
	}
	//cout << countZero << endl;
	return countZero;
}

void combination(vector<char> result, int num) {
	if (num == numOfCctv) {
		int area = getArea(result);
		if (area < minSquare)
			minSquare = area;
		return;
	}
	if (cctvInfo[num] == 1) {
		for (int i = 0; i < cctv[1].size(); i++) {
			result[num] = cctv[1][i];
			combination(result, num + 1);
		}
	}
	else if (cctvInfo[num] == 2) {
		for (int i = 0; i < cctv[2].size(); i++) {
			result[num] = cctv[2][i];
			combination(result, num + 1);
		}
	}
	else if (cctvInfo[num] == 3) {
		for (int i = 0; i < cctv[3].size(); i++) {
			result[num] = cctv[3][i];
			combination(result, num + 1);
		}
	}
	else if (cctvInfo[num] == 4) {
		for (int i = 0; i < cctv[4].size(); i++) {
			result[num] = cctv[4][i];
			combination(result, num + 1);
		}
	}
	else if (cctvInfo[num] == 5) {
		result[num] = 'a';
		combination(result, num + 1);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cctv[1] = {'e', 'w', 's', 'n'};
	cctv[2] = { 'h', 'v' }; //horizontal, vertical
	cctv[3] = { 'e', 'w', 's', 'n' };
	cctv[4] = { 'e', 'w', 's', 'n' };
	cctv[5] = { 'a' };
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m));
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			v[i][j] = temp;
			if (temp != 0 && temp != 6) {
				numOfCctv++;
				cctvLocation.push_back(make_pair(i, j));
				cctvInfo.push_back(temp);
			}
		}
	}
	combination(vector<char>(numOfCctv), 0);
	cout << minSquare;
	return 0;
}
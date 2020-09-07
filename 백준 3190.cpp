#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k, l; //n은 보드의 크기, k는 사과의 개수, l은 방향 변환 횟수
	cin >> n >> k;
	vector<vector<int>> v(n, vector<int>(n));
	int row, col;
	for (int i = 0; i < k; i++) {
		cin >> row >> col;
		v[row - 1][col - 1] = 1; //사과는 1 몸은 2
	}
	cin >> l;
	int second;
	char c;
	queue <pair<int, char>> q;
	for (int i = 0; i < l; i++) {
		cin >> second >> c;
		if (c == 'D') {
			q.push(make_pair(second, 'r')); //오른쪽
		}
		else {
			q.push(make_pair(second, 'l')); //왼쪽
		}
	}
	v[0][0] = 2;
	int index = 0;
	row = 0;
	col = 0;
	char direction[4] = { 'e', 's', 'w', 'n' }; //동, 남, 서, 북
	second = 0;
	int tailRow = 0;
	int tailCol = 0;
	/*cout << second << "초" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	queue<pair<int, int>> tailQueue;
	tailQueue.push(make_pair(0, 0));
	while (true) {
		second++;
		if (!q.empty() && q.front().first + 1 == second) {
			pair<int, char> p = q.front();
			q.pop();
			if (p.second == 'r') {
				index = (index + 1) % 4;
			}
			else {
				index = (index - 1 + 4) % 4;
			}

		}
		if (direction[index] == 'e') {
			if (col + 1 >= n) {
				break;
			}
			col++;
			if (v[row][col] == 2) { //자기 자신이랑 박으면
				break;
			}
			if (v[row][col] == 1) { //사과가 있으면
				v[row][col] = 2;
				tailQueue.push(make_pair(row, col));
			}
			else { //사과가 없으면
				v[row][col] = 2;
				tailQueue.push(make_pair(row, col));
				pair<int, int> tail = tailQueue.front();
				tailQueue.pop();
				v[tail.first][tail.second] = 0;
			}
		}
		else if (direction[index] == 's') { //남쪽
			if (row + 1 >= n) {
				break;
			}
			row++;
			if (v[row][col] == 2) {
				break;
			}
			if (v[row][col] == 1) { //사과가 있으면
				v[row][col] = 2;
				tailQueue.push(make_pair(row, col));
			}
			else { //사과가 없으면
				v[row][col] = 2;
				tailQueue.push(make_pair(row, col));
				pair<int, int> tail = tailQueue.front();
				tailQueue.pop();
				v[tail.first][tail.second] = 0;
			}
		}
		else if (direction[index] == 'w') {
			if (col - 1 < 0) {
				break;
			}
			col--;
			if (v[row][col] == 2) { //자기자신과 부딪히면
				break;
			}
			if (v[row][col] == 1) { //사과가 있으면
				v[row][col] = 2;
				tailQueue.push(make_pair(row, col));
			}
			else { //사과가 없으면
				v[row][col] = 2;
				tailQueue.push(make_pair(row, col));
				pair<int, int> tail = tailQueue.front();
				tailQueue.pop();
				v[tail.first][tail.second] = 0;
			}
		}
		else if (direction[index] == 'n') {
			if (row - 1 < 0) {
				break;
			}
			row--;
			if (v[row][col] == 2) { //자기자신과 부딪히면
				break;
			}
			if (v[row][col] == 1) { //사과가 있으면
				v[row][col] = 2;
				tailQueue.push(make_pair(row, col));
			}
			else { //사과가 없으면
				v[row][col] = 2;
				tailQueue.push(make_pair(row, col));
				pair<int, int> tail = tailQueue.front();
				tailQueue.pop();
				v[tail.first][tail.second] = 0;
			}
		}
		/*cout << second << "초" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	cout << second;
	return 0;
}
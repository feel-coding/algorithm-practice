#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, r, c;
int cnt = 0;
int result;
bool found = false;

void visit(int rowStart, int rowEnd, int colStart, int colEnd) {
	if (found)
		return;
	if (rowEnd - rowStart == 1) {
		if (++cnt && rowStart == r && colStart == c) {
			//cnt++;
			result = cnt;
			found = true;
			return;
		}
		else if (++cnt && rowStart == r && colEnd == c) {
			//cnt++;
			result = cnt;
			found = true;
			return;
		}
		else if (++cnt && rowEnd == r && colStart == c) {
			//cnt++;
			result = cnt;
			found = true;
			return;
		}
		else if (++cnt && rowEnd == r && colEnd == c) {
			//cnt++;
			result = cnt;
			found = true;
			return;
		}
		else {
			//cnt += 4;
			return;
		}
	}
	visit(rowStart, rowStart + (rowEnd + 1 - rowStart) / 2 - 1, colStart, colStart + (colEnd + 1 - colStart) / 2 - 1);
	visit(rowStart, rowStart + (rowEnd + 1 - rowStart) / 2 - 1, colStart + (colEnd + 1 - colStart) / 2, colEnd);
	visit(rowStart + (rowEnd + 1 - rowStart) / 2, rowEnd, colStart, colStart + (colEnd + 1 - colStart) / 2 - 1);
	visit(rowStart + (rowEnd + 1 - rowStart) / 2, rowEnd, colStart + (colEnd + 1 - colStart) / 2, colEnd);
}

int main() {
	cin >> n >> r >> c;
	n = pow(2, n);
	visit(0, n - 1, 0, n - 1);
	cout << result - 1;
	return 0;
}
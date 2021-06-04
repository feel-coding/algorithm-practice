#include <iostream>
using namespace std;

int scores[4][27] = { {0, 5, 10, 15, 20, 50, 30, 35, 40, 45, 100, 55, 60, 65, 70, 75, 80, 85, 90, 95, 500, 1000},
					 {0, 5, 10, 15, 20, 50, 275, 250, 300, 150, 175, 75, 80, 85, 90, 95, 500, 1000},
					 {0, 5, 10, 15, 20, 50, 30, 35, 40, 45, 100, 150, 125, 300, 350, 400, 500, 1000},
					 {0, 5, 10, 15, 20, 50, 275, 250, 300, 350, 400, 500, 1000} };

int main() {
	int move;
	int scoreType = 0;
	int current = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> move;
		current += move;
		if (scores[scoreType][current] == 50) {
			scoreType++;
		}
		else if (scores[scoreType][current] == 100) {
			scoreType += 2;
		}
		else if (scores[scoreType][current] == 300) {
			if (scoreType == 1) scoreType += 2;
		}
		else if (scores[scoreType][current] == 1000 || scores[scoreType][current] == 0) {
			cout << "1000";
			break;
		}
		cout << scores[scoreType][current] << " ";
	}
	return 0;
}

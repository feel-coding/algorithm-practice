#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Ap {
	int row;
	int col;
	int range;
	int speed;
};

int aMove[105];
int bMove[105];
int dr[5] = { 0, -1, 0, 1, 0 };
int dc[5] = { 0, 0, 1, 0, -1 };
Ap aps[5];

bool hasCommonAp(vector<int> aAps, vector<int> bAps) { // a�� b�� ���ÿ� ������ �����Ⱑ �ִ��� �Ǵ��ϴ� �Լ�
	for (int i = 0; i < aAps.size(); i++) {
		for (int j = 0; j < bAps.size(); j++) {
			if (aAps[i] == bAps[j]) return true;
		}
	}
	return false;
}

pair<int, int> getDownloadSpeed(int ap1, int ap2) {
	if (ap1 == ap2) {
		return make_pair(aps[ap1].speed / 2, aps[ap1].speed / 2);
	}
	else {
		return make_pair(aps[ap1].speed, aps[ap2].speed);
	}
}


int main() {
	int testCase, n, m, k, y, x, r, d, s, aRow, aCol, aDownload, bRow, bCol, bDownload;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		cin >> n >> m >> k; // k�� �������� ����
		for (int i = 0; i < k; i++) {
			cin >> aps[i].row >> aps[i].col >> aps[i].range >> aps[i].speed; // �������� ��ġ, ����, �ش� �������� �ٿ�ε� �ӵ�
		}
		cin >> s;
		for (int i = 1; i <= s; i++) {
			cin >> aMove[i];
		}
		for (int i = 1; i <= s; i++) {
			cin >> bMove[i];
		}
		cin >> aRow >> aCol >> aDownload >> bRow >> bCol >> bDownload;
		for (int sec = 0; sec <= s; sec++) {
			//cout << endl << "������ " << sec + 1 << "��\n";
			int aDir = aMove[sec];
			aRow += dr[aDir];
			aCol += dc[aDir];
			int bDir = bMove[sec];
			bRow += dr[bDir];
			bCol += dc[bDir];
			vector<int> aAps; // a�� ������ �������
			vector<int> bAps; // b�� ������ �������
			for (int i = 0; i < k; i++) {
				int aDistance = abs(aRow - aps[i].row) + abs(aCol - aps[i].col);
				int bDistance = abs(bRow - aps[i].row) + abs(bCol - aps[i].col);
				if (aDistance <= aps[i].range) {
					aAps.push_back(i);
				}
				if (bDistance <= aps[i].range) {
					bAps.push_back(i);
				}
			}
			if (!hasCommonAp(aAps, bAps)) { // a�� b�� ��ġ�� �����Ⱑ �ϳ��� ���ٸ�
				if (aAps.size() != 0) {
					int maxSpeed = 0;
					for (int i = 0; i < aAps.size(); i++) {
						int ap = aAps[i];
						if (aps[ap].speed > maxSpeed) {
							maxSpeed = aps[ap].speed;
						}
					}
					if (aDownload - maxSpeed >= 0) {
						aDownload -= maxSpeed;
					}
					else {
						aDownload = 0;
					}
				}
				if (bAps.size() != 0) {
					int maxSpeed = 0;
					for (int i = 0; i < bAps.size(); i++) {
						int ap = bAps[i];
						if (aps[ap].speed > maxSpeed) {
							maxSpeed = aps[ap].speed;
						}
					}
					if (bDownload - maxSpeed >= 0) {
						bDownload -= maxSpeed;
					}
					else {
						bDownload = 0;
					}
				}
			}
			else { // ��ġ�� �����Ⱑ �ִٸ�
				int maxDownload = 0;
				int maxA;
				int maxB;
				for (int i = 0; i < aAps.size(); i++) {
					for (int j = 0; j < bAps.size(); j++) {
						pair<int, int> abDownload = getDownloadSpeed(aAps[i], bAps[j]);
						if (abDownload.first + abDownload.second > maxDownload) {
							maxDownload = abDownload.first + abDownload.second;
							maxA = abDownload.first;
							maxB = abDownload.second;
						}
						else if (abDownload.first + abDownload.second == maxDownload) {
							if (aDownload > bDownload && abDownload.first > maxA || bDownload > aDownload && abDownload.second > maxB) {
								maxA = abDownload.first;
								maxB = abDownload.second;
							}
						}
					}
				}
				if (aDownload - maxA >= 0) {
					aDownload -= maxA;
				}
				else {
					aDownload = 0;
				}
				if (bDownload - maxB >= 0) {
					bDownload -= maxB;
				}
				else {
					bDownload = 0;
				}
			}
		}
		cout << "#" << t << " " << aDownload << " " << bDownload << '\n';
	}
	return 0;
}


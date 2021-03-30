#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
int peopleCount;
char arr[15][15];
int store[5][2]; // ���� ���� �ο�, ���� ���� �ð�
int peopleLocation[10][2];
int storeLocation[5][2];
int result[10];
int dist[10];
int minMinue = 10000;
queue<tuple<int, int, int>> waitingPeople[5];
queue<tuple<int, int, int>> currentPeople[5];

struct Person {
	int personNum;
	int storeNum;
	int distance;
};

bool compare(const Person& p1, Person& p2) {
	return p1.distance < p2.distance;
}



int getMinute() { // result��� ���� ������ �湮���� �� �ɸ��� �ּ� �ð�
	/*cout << endl;
	for (int i = 0; i < peopleCount; i++) {
		cout << result[i] << " ";
	}
	cout << endl;*/
	Person peopleAndDistance[10];
	for (int i = 0; i < peopleCount; i++) {
		int storeNum = result[i];
		int storeRow = storeLocation[storeNum][0];
		int storeCol = storeLocation[storeNum][1];
		dist[i] = abs(storeRow - peopleLocation[i][0]) + abs(storeCol - peopleLocation[i][1]);
		peopleAndDistance[i] = { i, storeNum, dist[i] };
	}
	sort(peopleAndDistance, peopleAndDistance + peopleCount, compare);
	for (int i = 0; i < peopleCount; i++) {
		//cout << peopleAndDistance[i].personNum + 1 << "�� ���, " << peopleAndDistance[i].storeNum + 1<< "�� ���µ� " << peopleAndDistance[i].distance << "�� �ɸ�" << endl;
		waitingPeople[peopleAndDistance[i].storeNum].push(make_tuple(peopleAndDistance[i].personNum, peopleAndDistance[i].storeNum, peopleAndDistance[i].distance));
	}
	int m;
	for (m = 0; ; m++) { // 1�о� �÷����鼭
		//cout << m << "��" << endl;
		for (int i = 0; i < k; i++) {
			while (!currentPeople[i].empty() && get<2>(currentPeople[i].front()) == m) {
				//cout << get<0>(currentPeople[i].front()) + 1 << "�� ����� " << get<1>(currentPeople[i].front()) + 1 << "�� ������ ����������" << endl;
				currentPeople[i].pop(); // ���� ���ѽð��� �� �Ǿ� ������ �� ����� �������´�
			}
		}
		for (int i = 0; i < k; i++) {
			while (currentPeople[i].size() < store[i][0] && !waitingPeople[i].empty() && get<2>(waitingPeople[i].front()) <= m) { // ���� ������ �� ���� �ʾҰ� ������� ����� ������
				tuple<int, int, int> currentPerson = waitingPeople[i].front();
				waitingPeople[i].pop();
				get<2>(currentPerson) = m + store[i][1]; // ���������� �ϴ� �ð� = ���� �ð� + ���� ���ѽð�
				currentPeople[i].push(currentPerson);
				//cout << get<0>(currentPerson) + 1 << "�� ��� " << get<1>(currentPerson) + 1 << "�� ���� ����" << endl;
			}
		}
		int flag = true;
		for (int i = 0; i < k; i++) {
			if (!waitingPeople[i].empty() || !currentPeople[i].empty()) {
				flag = false;
				break;
			}

		}
		if (flag) break;
	}
	//cout << "�� " << m << "�� �ɸ�" << endl;

	return m;
}

void pickStore(int current) {
	if (current == peopleCount) {
		int minute = getMinute();
		if (minute < minMinue) {
			minMinue = minute;
		}
		return;
	}
	for (int i = 0; i < k; i++) {
		result[current] = i;
		pickStore(current + 1);
	}
}

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		minMinue = 10000;
		peopleCount = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			cin >> store[i][0] >> store[i][1];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '1') { // 1�� ���
					peopleLocation[peopleCount][0] = i;
					peopleLocation[peopleCount][1] = j;
					peopleCount++;
				}
				else if (arr[i][j] >= 'A') {
					storeLocation[arr[i][j] - 'A'][0] = i;
					storeLocation[arr[i][j] - 'A'][1] = j;
				}
			}
		}
		pickStore(0);
		cout << "#" << t << " " << minMinue << endl;
	}
	return 0;
}
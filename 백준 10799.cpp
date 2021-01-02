#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	int cnt = 0; // �� ������ �ִ� �踷���
	int stickNum = 0; // ������� �߸� ����� ���� ����
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (i < s.size() - 1 && s[i + 1] == ')') { // �������϶�
				stickNum += cnt;
				i++;
			}
			else { // �������� �ƴ� ��
				cnt++;
			}
		}
		else { // �ݴ� ��ȣ�� ��
			cnt--;
			stickNum++;
		}
	}
	cout << stickNum;
	return 0;
}
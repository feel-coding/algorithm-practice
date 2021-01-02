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
	int cnt = 0; // 현 시점에 있는 쇠막대기
	int stickNum = 0; // 현재까지 잘린 막대기 조각 개수
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (i < s.size() - 1 && s[i + 1] == ')') { // 레이저일때
				stickNum += cnt;
				i++;
			}
			else { // 레이저가 아닐 때
				cnt++;
			}
		}
		else { // 닫는 괄호일 때
			cnt--;
			stickNum++;
		}
	}
	cout << stickNum;
	return 0;
}
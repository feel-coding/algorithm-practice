#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		int k;
		string s;
		cin >> k >> s;
		vector<string> clockwise; // 시계방향
		vector<string> counterclockwise; // 시계 반대 방향
		set<string> stringSet; // 오름차순으로 정렬하여 중복 없이 저장
		for (int i = 0; i < 18; i++) {
			string temp = "   ";
			temp[0] = s[i];
			temp[1] = s[(i + 1) % 18];
			temp[2] = s[(i + 2) % 18];
			clockwise.push_back(temp);
			stringSet.insert(temp);
			temp[0] = s[(18 - i) % 18];
			temp[1] = s[(19 - i) % 18];
			temp[2] = s[(20 - i) % 18];
			counterclockwise.push_back(temp);
		}
		set<string>::iterator iter = stringSet.begin();
		for (int i = 0; i < k - 1; i++) {
			iter++;
		}
		string password = *iter; // k번째 비밀번호
		int minIndex = 18; // 최소 회전 횟수
		for (int i = 0; i < 18; i++) {
			if (clockwise[i] == password && i < minIndex) {
				minIndex = i;
				break;
			}
			if (counterclockwise[i] == password && i < minIndex) {
				minIndex = i;
				break;
			}
		}
		int decimalNum = 0;
		if (password[2] <= '9') {
			decimalNum += password[2] - '0';
		}
		else {
			decimalNum += password[2] - 'A' + 10;
		}
		if (password[1] <= '9') {
			decimalNum += (password[1] - '0') * 32;
		}
		else {
			decimalNum += (password[1] - 'A' + 10) * 32;
		}
		if (password[0] <= '9') {
			decimalNum += (password[0] - '0') * 32 * 32;
		}
		else {
			decimalNum += (password[0] - 'A' + 10) * 32 * 32;
		}
		cout << "#" << t << " " << minIndex << " " << decimalNum << endl;
	}
	return 0;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 0;
	int minLength = s.size();
	for (int i = 1; i < s.size(); i++) {
		string result = "";
		string temp = "";
		int cnt = 1;
		bool end = false;
		for (int j = 0; j < s.size(); j += i) {
			if (j + i - 1 >= s.size()) {
				if (cnt != 1) {
					result += to_string(cnt);
				}
				result += temp;
				result += s.substr(j, s.size() - j);
				end = true;
			}
			else if (s.substr(j, i) == temp) { // 하나 앞 덩어리와 문자열이 일치한다면
				cnt++;
			}
			else { // 다르다면
				if (cnt != 1) {
					result += to_string(cnt);
				}
				result += temp;
				temp = s.substr(j, i);
				cnt = 1;
			}
		}
		if (!end) {
			if (cnt != 1) {
				result += to_string(cnt);
			}
			result += temp;
		}
		if (result.size() < minLength) {
			minLength = result.size();
		}
	}
	return minLength;
}

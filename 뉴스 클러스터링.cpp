#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
#include <set>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	map<string, int> m1;
	map<string, int> m2;
	set<string> s;
	transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	for (int i = 0; i < str1.size() - 1; i++) {
		string ss = str1.substr(i, 2);
		if (ss[0] >= 'A' && ss[0] <= 'Z' && ss[1] >= 'A' && ss[1] <= 'Z') {
			m1[ss]++;
			s.insert(ss);
		}
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		string ss = str2.substr(i, 2);
		if (ss[0] >= 'A' && ss[0] <= 'Z' && ss[1] >= 'A' && ss[1] <= 'Z') {
			m2[ss]++;
			s.insert(ss);
		}
	}
	int denominator = 0; // 분모
	int numerator = 0; // 분자
	for (set<string>::iterator iter = s.begin(); iter != s.end(); iter++) {
		denominator += max(m1[*iter], m2[*iter]);
		numerator += min(m1[*iter], m2[*iter]);
	}
	if (denominator == 0 && numerator == 0) return 65536;
	return numerator * 65536 / denominator;
}
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

int main() {
	vector<int> firstWord(26);
	vector<int> secondWord(26);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		firstWord[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++) {
		secondWord[s2[i] - 'a']++;
	}
	int count = 0;
	for (int i = 0; i < 26; i++) {
		count += (abs(firstWord[i] - secondWord[i]));
	}
	cout << count;
	return 0;
}
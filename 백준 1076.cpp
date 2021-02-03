#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, pair<string, string>> m;
	m["black"] = make_pair("0", "");
	m["brown"] = make_pair("1", "0");
	m["red"] = make_pair("2", "00");
	m["orange"] = make_pair("3", "000");
	m["yellow"] = make_pair("4", "0000");
	m["green"] = make_pair("5", "00000");
	m["blue"] = make_pair("6", "000000");
	m["violet"] = make_pair("7", "0000000");
	m["grey"] = make_pair("8", "00000000");
	m["white"] = make_pair("9", "000000000");
	string c1, c2, c3;
	cin >> c1 >> c2 >> c3;
	cout << stoll(m[c1].first + m[c2].first + m[c3].second);
	return 0;
}
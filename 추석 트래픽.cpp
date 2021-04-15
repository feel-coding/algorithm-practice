#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	int maxCount = 0;
	for (int i = 0; i < lines.size(); i++) {
		cout << endl;
		string hours = lines[i].substr(11, 2);
		string minutes = lines[i].substr(14, 2);
		string seconds = lines[i].substr(17, 2);
		string milliseconds = lines[i].substr(20, 3);
		int iMillisecond = stoi(milliseconds) + stoi(seconds) * 1000 + stoi(minutes) * 60 * 1000 + stoi(hours) * 60 * 60 * 1000;
		int cnt = 1;
		for (int j = i + 1; j < lines.size(); j++) {
			hours = lines[j].substr(11, 2);
			minutes = lines[j].substr(14, 2);
			seconds = lines[j].substr(17, 2);
			milliseconds = lines[j].substr(20, 3);
			int jMillisecond = stoi(milliseconds) + stoi(seconds) * 1000 + stoi(minutes) * 60 * 1000 + stoi(hours) * 60 * 60 * 1000;
			string timeString = "";
			for (int k = 24; ; k++) {
				if (lines[j].substr(k, 1) == "s") {
					break;
				}
				else if (lines[j].substr(k, 1) == ".") {
					continue;
				}
				timeString += lines[j].substr(k, 1);
			}
			while (true) {
				if (timeString.size() == 4) break;
				timeString += "0";
			}
			int startTime = jMillisecond - stoi(timeString) + 1;
			if (startTime - iMillisecond <= 999) {
				cnt++;
			}
		}
		if (cnt > maxCount) {
			maxCount = cnt;
		}
	}
	return maxCount;
}
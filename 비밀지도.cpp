#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	string str = "";
	vector<vector<int>> v1(n, vector<int>(n));
	vector<vector<int>> v2(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		str += " ";
	}
	for (int i = 0; i < n; i++) {
		int num = arr1[i];
		vector<int> temp;
		while (num > 0) {
			temp.push_back(num % 2);
			num /= 2;
		}
		int index = n - 1;
		for (int j = 0; j < temp.size(); j++) {
			v1[i][index--] = temp[j];
		}
	}
	for (int i = 0; i < n; i++) {
		int num = arr2[i];
		vector<int> temp;
		while (num > 0) {
			temp.push_back(num % 2);
			num /= 2;
		}
		int index = n - 1;
		for (int j = 0; j < temp.size(); j++) {
			v2[i][index--] = temp[j];
		}
	}
	vector<string> answer(n, str);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v1[i][j] == 1 || v2[i][j] == 1) {
				answer[i][j] = '#';
			}
		}
	}
	return answer;
}
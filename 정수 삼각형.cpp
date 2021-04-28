#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[505][505];

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	for (int i = 1; i <= triangle.size(); i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= triangle.size(); i++) {
		if (dp[triangle.size()][i] > answer) {
			answer = dp[triangle.size()][i];
		}
	}
	return answer;
}

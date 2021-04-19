#include <string>
using namespace std;

int solution(string dartResult) {
	int result[5];
	int temp;
	int index = -1;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] >= '0' && dartResult[i] <= '9') {
			index++;
			if (dartResult[i + 1] == '0') {
				result[index] = 10;
				i++;
			}
			else {
				result[index] = dartResult[i] - '0';
			}
		}
		else if (dartResult[i] == 'D') {
			result[index] *= result[index];
		}
		else if (dartResult[i] == 'T') {
			result[index] *= result[index] * result[index];
		}
		else if (dartResult[i] == '*') {
			result[index] *= 2;
			if (index > 0) {
				result[index - 1] *= 2;
			}
		}
		else if (dartResult[i] == '#') {
			result[index] *= -1;
		}
	}
	return result[0] + result[1] + result[2];
}
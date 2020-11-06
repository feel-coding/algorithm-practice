#include <iostream>
#include <string>
using namespace std;


int main() {
	string wheel[4];
	int left[4];
	int right[4];
	for (int i = 0; i < 4; i++) {
		cin >> wheel[i];
		left[i] = 6;
		right[i] = 2;
	}
	int k;
	cin >> k;
	int* wheelNum = new int[k];
	int* direction = new int[k];
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		cin >> direction[i];
		wheelNum[i] = temp - 1;
	}
	for (int i = 0; i < k; i++) {
		if (wheelNum[i] == 0) { //0번 톱니바퀴인 경우
			if (direction[i] == 1) { //시계 방향인 경우
				if (wheel[0][right[0]] != wheel[1][left[1]]) { //오른쪽 톱니바퀴(1번 톱니바퀴)와 맞닿는 부분이 다른 극일 때 시계 반대 방향으로 돌아야 함
					if (wheel[1][right[1]] != wheel[2][left[2]]) { //0번 톱니바퀴와 1번 톱니바퀴가 맞닿는 부분이 다른 극이면 0번 톱니바퀴가 시계방향으로 돌아야 함
						if (wheel[2][right[2]] != wheel[3][left[3]]) { //2번 톱니바퀴와 3번 톱니바퀴가 맞닿는 부분이 다른 극이면 3번이 시계반대방향으로 돌아야 함
							right[3] = (right[3] + 1) % 8;
							left[3] = (left[3] + 1) % 8;
						}
						right[2] = (right[2] - 1 + 8) % 8;
						left[2] = (left[2] - 1 + 8) % 8;
					}
					left[1] = (left[1] + 1) % 8;
					right[1] = (right[1] + 1) % 8;
				}
				right[0] = (right[0] - 1 + 8) % 8;
				left[0] = (left[0] - 1 + 8) % 8;
			}
			else { //시계 반대 방향인 경우
				if (wheel[0][right[0]] != wheel[1][left[1]]) { //오른쪽 톱니바퀴(1번 톱니바퀴)와 맞닿는 부분이 다른 극일 때 시계 방향으로 돌아야 함
					if (wheel[1][right[1]] != wheel[2][left[2]]) { //0번 톱니바퀴와 1번 톱니바퀴가 맞닿는 부분이 다른 극이면 0번 톱니바퀴가 시계방향으로 돌아야 함
						if (wheel[2][right[2]] != wheel[3][left[3]]) { //2번 톱니바퀴와 3번 톱니바퀴가 맞닿는 부분이 다른 극이면 3번이 시계반대방향으로 돌아야 함
							right[3] = (right[3] - 1 + 8) % 8;
							left[3] = (left[3] - 1 + 8) % 8;
						}
						right[2] = (right[2] + 1) % 8;
						left[2] = (left[2] + 1) % 8;
					}
					left[1] = (left[1] - 1 + 8) % 8;
					right[1] = (right[1] - 1 + 8) % 8;
				}
				right[0] = (right[0] + 1) % 8;
				left[0] = (left[0] + 1) % 8;
			}
		}






		else if (wheelNum[i] == 1) {
			if (direction[i] == 1) { //시계 방향인 경우
				if (wheel[1][right[1]] != wheel[2][left[2]]) { //시계 반대 방향으로 돌아야 함
					if (wheel[2][right[2]] != wheel[3][left[3]]) {
						left[3] = (left[3] - 1 + 8) % 8;
						right[3] = (right[3] - 1 + 8) % 8;
					}
					left[2] = (left[2] + 1) % 8;
					right[2] = (right[2] + 1) % 8;
				}
				if (wheel[0][right[0]] != wheel[1][left[1]]) { //왼쪽 톱니바퀴(0번 톱니바퀴)와 맞닿는 부분이 다른 극일 때 시계 반대 방향으로 돌아야 함
					left[0] = (left[0] + 1) % 8;
					right[0] = (right[0] + 1) % 8;
				}
				right[1] = (right[1] - 1 + 8) % 8;
				left[1] = (left[1] - 1 + 8) % 8;
			}
			else { //1번 톱니바퀴이고 반시계 방향인 경우
				if (wheel[1][right[1]] != wheel[2][left[2]]) { //시계 반대 방향으로 돌아야 함
					if (wheel[2][right[2]] != wheel[3][left[3]]) {
						left[3] = (left[3] + 1) % 8;
						right[3] = (right[3] + 1) % 8;
					}
					left[2] = (left[2] - 1 + 8) % 8;
					right[2] = (right[2] - 1 + 8) % 8;
				}
				if (wheel[0][right[0]] != wheel[1][left[1]]) { //왼쪽 톱니바퀴(0번 톱니바퀴)와 맞닿는 부분이 다른 극일 때 시계 반대 방향으로 돌아야 함
					left[0] = (left[0] - 1 + 8) % 8;
					right[0] = (right[0] - 1 + 8) % 8;
				}
				right[1] = (right[1] + 1) % 8;
				left[1] = (left[1] + 1) % 8;
			}
		}
		else if (wheelNum[i] == 2) { //2번 톱니바퀴인 경우
			if (direction[i] == 1) { //시계 방향인 경우
				if (wheel[2][right[2]] != wheel[3][left[3]]) { //오른쪽 톱니바퀴(3번 톱니바퀴)와 맞닿는 부분이 다른 극일 때 3번 톱니바퀴가 시계 반대 방향으로 돌아야 함
					left[3] = (left[3] + 1) % 8;
					right[3] = (right[3] + 1) % 8;
				}
				if (wheel[2][left[2]] != wheel[1][right[1]]) { //왼쪽 톱니바퀴(1번 톱니바퀴)와 맞닿는 부분이 다른 극일 때 시계 반대 방향으로 돌아야 함
					if (wheel[0][right[0]] != wheel[1][left[1]]) { //0번 톱니바퀴와 1번 톱니바퀴가 맞닿는 부분이 다른 극이면 0번 톱니바퀴가 시계방향으로 돌아야 함
						right[0] = (right[0] - 1 + 8) % 8;
						left[0] = (left[0] - 1 + 8) % 8;
					}
					left[1] = (left[1] + 1) % 8;
					right[1] = (right[1] + 1) % 8;
				}
				right[2] = (right[2] - 1 + 8) % 8;
				left[2] = (left[2] - 1 + 8) % 8;
			}
			else { //2번 톱니바퀴이고 반시계 방향인 경우
				if (wheel[2][right[2]] != wheel[3][left[3]]) { //오른쪽 톱니바퀴(3번 톱니바퀴)와 맞닿는 부분이 다른 극일 때 3번 톱니바퀴가 시계 방향으로 돌아야 함
					left[3] = (left[3] - 1 + 8) % 8;
					right[3] = (right[3] - 1 + 8) % 8;
				}
				if (wheel[2][left[2]] != wheel[1][right[1]]) { //왼쪽 톱니바퀴(1번 톱니바퀴)와 맞닿는 부분이 다른 극일 때 시계 방향으로 돌아야 함
					if (wheel[0][right[0]] != wheel[1][left[1]]) { //0번 톱니바퀴와 1번 톱니바퀴가 맞닿는 부분이 다른 극이면 0번 톱니바퀴가 시계반대방향으로 돌아야 함
						right[0] = (right[0] + 1) % 8;
						left[0] = (left[0] + 1) % 8;
					}
					left[1] = (left[1] - 1 + 8) % 8;
					right[1] = (right[1] - 1 + 8) % 8;
				}
				right[2] = (right[2] + 1) % 8;
				left[2] = (left[2] + 1) % 8;
			}
		}
		else { //3번 톱니바퀴인 경우
			if (direction[i] == 1) { //시계 방향인 경우
				if (wheel[3][left[3]] != wheel[2][right[2]]) { //2가 시계반대 방향으로 돌아야 함
					if (wheel[1][right[1]] != wheel[2][left[2]]) { //1이 시계 방향으로 돌아야 함
						if (wheel[0][right[0]] != wheel[1][left[1]]) { //0이 시계 반대 방향으로 돌아야 함
							right[0] = (right[0] + 1) % 8;
							left[0] = (left[0] + 1) % 8;
						}
						right[1] = (right[1] - 1 + 8) % 8;
						left[1] = (left[1] - 1 + 8) % 8;
					}
					left[2] = (left[2] + 1) % 8;
					right[2] = (right[2] + 1) % 8;
				}
				right[3] = (right[3] - 1 + 8) % 8;
				left[3] = (left[3] - 1 + 8) % 8;
			}
			else { //시계 반대 방향인 경우
				if (wheel[3][left[3]] != wheel[2][right[2]]) { //2가 시계방향으로 돌아야 함
					if (wheel[1][right[1]] != wheel[2][left[2]]) { //1이 시계 반대 방향으로 돌아야 함
						if (wheel[0][right[0]] != wheel[1][left[1]]) { //0이 시계 방향으로 돌아야 함
							right[0] = (right[0] - 1 + 8) % 8;
							left[0] = (left[0] - 1 + 8) % 8;
						}
						right[1] = (right[1] + 1) % 8;
						left[1] = (left[1] + 1) % 8;
					}
					left[2] = (left[2] - 1 + 8) % 8;
					right[2] = (right[2] - 1 + 8) % 8;
				}
				right[3] = (right[3] + 1) % 8;
				left[3] = (left[3] + 1) % 8;
			}
		}
	}
	int sum = 0;
	if (wheel[0][(left[0] + 2) % 8] == '1') {
		sum += 1;
	}
	if (wheel[1][(left[1] + 2) % 8] == '1') {
		sum += 2;
	}
	if (wheel[2][(left[2] + 2) % 8] == '1') {
		sum += 4;
	}
	if (wheel[3][(left[3] + 2) % 8] == '1') {
		sum += 8;
	}
	cout << sum << endl;
	return 0;
}
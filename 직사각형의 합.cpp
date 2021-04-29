#include <iostream>
using namespace std;

int arr[1005][1005];
int sum[1005][1005];

int n, m, q, a, b, c, d;

int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c >> d;
		a++;
		b++;
		c++;
		d++;
		cout << sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1] << '\n';
	}
	return 0;
}

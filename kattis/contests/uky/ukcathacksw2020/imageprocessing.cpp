#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	int h, w, n, m;
	cin >> h >> w >> n >> m;
	vector<vector<int> > image(h, vector<int>(w));
	vector<vector<int> > kernel(n, vector<int>(m));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int p; cin >> p;
			image[i][j] = p;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int p; cin >> p;
			kernel[n - i - 1][m - j - 1] = p;
		}
	}

	for (int i = 0; i < h - n + 1; i++) {
		for (int j = 0; j < w - m + 1; j++) {
			int sum = 0;
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					sum += image[i + x][j + y] * kernel[x][y];
				}
			}
			cout << sum << " ";
		}
		cout << "\n";
	}
}

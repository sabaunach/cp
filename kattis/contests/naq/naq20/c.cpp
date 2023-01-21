#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char board[8][8];

int solve() {
	int nqueens = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char c; cin >> c;
			board[i][j] = c;
			if (c == '*') {
				nqueens++;
				for (int k = i - 1; k >= 0; k--) {
					if (board[k][j] == '*') {
						cout << "invalid";
						return 0;
					}
				}
				for (int k = j - 1; k >= 0; k--) {
					if (board[i][k] == '*') {
						cout << "invalid";
						return 0;
					}
				}
				for (int k = min(i, j); k > 0; k--) {
					if (board[i - k][j - k] == '*') {
						cout << "invalid";
						return 0;
					}
				}
				// this case not working V
				for (int k = min(i, 8 - j); k > 0; k--) {
					if (board[i - k][j - k] == '*') {
						cout << "invalid";
						return 0;
					}
				}
			}
		}
	}
	if (nqueens != 8) {
		cout << "invalid";
		return 0;
	}
	cout << "valid";
	return 0;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}

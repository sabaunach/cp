#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int words[26][26];

void solve() {
	int n; cin >> n;
	while (n--) {
		string in; cin >> in;
		int first = in[0] - 'A', last = in[in.length() - 1] - 'A';
		words[first][last]++;
	}
	ll total = 0;
	// the value of words[a][b] means n words begin with a, end with b
	// consider the square i j
	//                     k l
	// pick ij, pick ik, pick jl, and kl is determined
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (!words[i][j])
				continue;
			ll ways_ij = words[i][j];
			words[i][j]--; // don't count same word twice in same square
			for (int k = 0; k < 26; k++) {
				if (!words[i][k])
					continue;
				ll ways_ik = words[i][k];
				words[i][k]--;
				for (int l = 0; l < 26; l++) {
					if (!words[j][l])
						continue;
					ll ways_jl = words[j][l];
					words[j][l]--;
					total += (ways_ij) * (ways_ik) * (ways_jl) * (words[k][l]);
					words[j][l]++;
				}
				words[i][k]++;
			}
			words[i][j]++;
		}
	}
	cout << total;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}

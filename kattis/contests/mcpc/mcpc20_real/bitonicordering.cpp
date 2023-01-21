#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

// From cp-algo website
struct FenwickTree {
    vector<ull> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ull> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ull sum(int r) {
        ull ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ull sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ull delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve() {
	int n; cin >> n;
	FenwickTree ft(n);
	vector<pair<ull, int>> num_index(n);
	for (int t = 0; t < n; t++) {
		ull in; cin >> in;
		num_index[t] = {in, t};
	}
	sort(num_index.begin(), num_index.end());
	
	ull total = 0;
	for (int i = 0; i < n; i++) {
		// push to left or right (min approach)
		int index = num_index[i].second;
		int m = min(index - ft.sum(0, index - 1), n - index - 1 - ft.sum(index + 1, n - 1));
		total += m;
		assert(m >= 0);
		ft.add(index, 1);
	}
	cout << total << endl;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}

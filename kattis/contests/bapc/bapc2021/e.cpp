#include <bits/stdc++.h>

using namespace std;

bool test = false;

int main() {

    int n;

    srand(time(NULL));
    string a,b;
    if (test) {
        map<int, char> m = {{0,'A'},{1,'C'},{2,'T'},{3,'G'}};
        n = 1e6;
        for (int i = 0; i < n; i++) {
            a.push_back(m[rand() % 4]);
            b.push_back(m[rand() % 4]);
        }
    } else {
        cin >> n;
        cin >> a >> b;
    }

    int i = 0, j = 0;
    vector<char> seq;
    // for (int it = 0; seq.size() < n/2; it++) {
    //     if (!(it%10)) cout << it << endl;
    //     seq.clear();
    while (i < n && j < n) {
        int di = n, dj = n;
        // cout << i << " " << j << endl;
        for (auto& c: {'A','C','T','G'}) {
            int mi = i, mj = j;
            while (mi < n && a[mi] != c) mi++;
            if (mi >= n) continue;
            while (mj < n && b[mj] != c) mj++;
            if (mj >= n) continue;
            if (mi + mj < di+dj) di=mi, dj=mj;
        }
        if (di >= n || dj >= n) break;
        i=di, j=dj;
        seq.push_back(a[i]);
        i++, j++;
    }
    // }

    for (auto&c: seq) cout << c;
    // cout << endl << seq.size() << endl;
    // assert(seq.size() >= n/2);
    cout << "\n";
}
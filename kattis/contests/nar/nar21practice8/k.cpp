#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if (s1.length() > s2.length()) swap(s1, s2);
    s3 = s1;
    s4 = s2;
    string out1, out2;

    for (int i = 0; i < s1.length(); i++) {

    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}

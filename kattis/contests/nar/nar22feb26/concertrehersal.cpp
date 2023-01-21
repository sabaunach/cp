#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, P, K;
int d[200000], nxt[200000], cnt[200000];
bool seen[200000];
void solve() {
    cin >> N >> P >> K;
    ll dsum = 0;
    for (int i = 0; i < N; i++) { cin >> d[i]; dsum += d[i]; }

    int j = 0;
    // based on # times we lap from start
    int count = (int)(P / dsum);
    ll sum = count * dsum;

    for (int i = 0; i < N; i++) {
        while (sum + d[j] <= P) {
            sum += d[j];
            j++;
            if (j == N) {
                j = 0;
                count++;
            }
        }
        nxt[i] = j;
        cnt[i] = count;
        sum -= d[i];
    }

    vector<int> st;
    int s = 0, len = 0;
    ll tot = 0;
    for (; K > 0; K--) {
        if (!seen[s]) {
                st.push_back(s);
                seen[s] = true;
                s = nxt[s];
        } else {
            int t;
            do {
                t = st.back(); st.pop_back();
                tot += cnt[t];
                len++;
            } while (t != s);
            tot += (K / len)*tot;
            K = (K % len);

            // the remaining days
            for (; K > 0; K--) {
                tot += cnt[s];
                s = nxt[s];
            }
        }
    }
    // the days prior to first cycle
    while (!st.empty()) {
        tot += cnt[st.back()]; st.pop_back();
    }
    cout << tot << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}

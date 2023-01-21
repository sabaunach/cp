#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto& i : v) cin >> i;
    int q; cin >> q;

    vector<bool> vis(n);
    bool stop;
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        int x = v[i];
        vis[x-1] = 1;
        while(x != i + 1) {
            if(x == q) stop = true;
            x = v[x-1];
            vis[x-1] = 1;
            if(stop) break;
        }
        if(stop) break;
    }

    for(int i = 0; i < n; i++)
        if(vis[i]) cout << i+1 << " ";
        else cout << v[i] << " ";
}
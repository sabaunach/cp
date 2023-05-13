#include <bits/stdc++.h>

using namespace std;

int main() {
    int h,w; cin >> h >> w;
    int H = h*2+1, W = w*2+1;
    vector<vector<pair<int, double>>> adj(H*W);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c; cin >> c;
            if (j+1 < w)
            adj[i*w+j+1].push_back({i*w+j+1, 10});
            if (i+2 < h)
            adj[(i+1)*w+j].push_back({i*w+j+1, 10});
            if (c=='O') {
                if (j+1 < w && i+1 < h)
                    adj[].push_back({(i+1)*w+j+1, });
            }
        }
    }

    priority_queue<pair<double, int>> pq;

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >>n>>m;
    vector<pair<double,double>> pos;
    unordered_set<int> move;
    for(int i = 0; i < n; i++) {
        int a,b;cin>>a>>b;
        pos.emplace_back(a,b);
        if (a==b &&b==-1) move.insert(i);
    }

    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++) {
        int a,b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int miter = 100000;
    for(int x=0;x<miter;x++){
//        cout <<x<<endl;
        vector<pair<double,double>> npos;
        for(int i = 0; i < n; i++) {
            if (move.find(i) == move.end()) npos.push_back(pos[i]);
            else {
                double nx=0,ny=0;
                for(auto nn:adj[i]) {
                    nx += pos[nn].first;
                    ny+=pos[nn].second;
                }
                nx/=1.0*adj[i].size();
                ny/=1.0*adj[i].size();
                if (pos[i].first == -1)
                    npos.emplace_back(nx,ny);
                else {
                    nx=(nx+pos[i].first)/2.0;
                    ny=(ny+pos[i].second)/2.0;
                    npos.emplace_back(nx,ny);
                }
            }
        }
        swap(pos,npos);
    }

    for(auto p : pos)
        cout << p.first << " " << p.second << endl;
}
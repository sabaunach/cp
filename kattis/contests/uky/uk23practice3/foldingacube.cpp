#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> m = {
        {"0",0},
        {"2a",1}, {"3a",2}, {"4a",3}, {"5a",4}, {"6a",5},
        {"2b",6}, {"3b",7}, {"4b",8}, {"5b",9}, {"6b",10},
        {"2c",11}, {"3c",12}, {"4c",13}, {"5c",14}, {"6c",15},
        {"2d",16}, {"3d",17}, {"4d",18}, {"5d",19}, {"6d",20}

};

vector<vector<string>> adj = {
        {"2a","3a","4a","5a"},
        {"6a","3b","0","5b"},{"2b","6b","4b","0"},{"0","3c","6c","5c"},{"2c","0","4c","6d"},{"4d","3d","0","5d"},
        {"5b","6a","0","0"},{"6b","4b","0","0"},{"0","6c","5c","0"},{"6d","0","0","4c"},{"2d","5d","4d","0"},
        {"6a","0","0","3b"},{"0","2b","6b","0"},{"0","0","3c","6c"},{"0","0","6d","2c"},{"0","3d","2d","5d"},
        {"0","3b","0","5b"},{"4b","0","2b","0"},{"0","5c","0","3c"},{"2c","0","4c","0"},{"4d","0","2d","3d"}
};

#define rep(i,a,b) for(int i = a; i < b; i++)
int main() {
    vector<vector<char>> input(6, vector<char>(6));
    pair<int, int> start;
    rep(i,0,6) rep(j,0,6) {
        cin >> input[i][j];
        if (input[i][j] == '#')
            start = {i,j};
    }
    set<pair<int, int>> vis = {start};
    set<int> faces = {1};
    queue<pair<string, pair<int, int>>> q;
    q.push({"0", start});
    vector<pair<int,int>> vd = {{1,0},{0,-1},{-1,0},{0,1}};
    while (!q.empty()) {
        auto[s, ij] = q.front(); q.pop();
        auto[i,j] = ij;
        cout << s << " {" << i << ", " << j << "}\n";
        for (int d = 0; d < 4; d++) {
            auto[di,dj] = vd[d];
            if (!(0 <= i+di && i+di <= 5 && 0 <= j+dj && j+dj <= 5)) continue;
            if (input[i+di][j+dj] == '.') continue;
            if (vis.count({i+di,j+dj})) continue;

            string nxt = adj[m[s]][d];
            int nxt_face = nxt[0]-'0';
            if (!nxt_face) continue;
            // if (faces.count(nxt_face)) continue;
            faces.insert(nxt_face);
            vis.emplace(i+di,j+dj);
            q.push({nxt, {i+di,j+dj}});
        }
    }
    cout << (faces.size()==6?"can fold":"cannot fold");
}
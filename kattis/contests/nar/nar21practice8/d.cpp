#include <bits/stdc++.h>

using namespace std;
int ret = INT_MAX;

void dfs(int currNode, int lastNode, int prevNeed, unordered_map<int, unordered_map<int, pair<int,int>>> & m){
    int need = max(prevNeed, m[lastNode][currNode].first) - m[lastNode][currNode].second;
    ret = min(need, ret);
    for(auto &i : m[currNode]){
        dfs(i.first, currNode, need, m);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, w;
    cin >> n >> w;
    // parent, child, max cap, curr water
    unordered_map<int, unordered_map<int, pair<int,int>>> m;
    for(int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        m[a][i] = {b, c};
    }
    ret = w;
    for(auto &i : m[0]){
        dfs(i.first, 0, w, m);
    }
    cout << ret << endl;
}
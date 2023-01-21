#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> v;
    priority_queue<pair<int, int>> stacks;
    int sum = 0;
    for (int i = 0, w; i < n && cin >> w; i++) {
        if (w > 0) stacks.push({w, i});
        sum += w;
    }
    if (sum % 2 || stacks.size() == 1) { cout << "no"; return 0; }


    while (!stacks.empty()) {
        if(stacks.size() == 1){
            cout << "no";
            return 0;
        }
        auto st1 = stacks.top(); stacks.pop();
        auto st2 = stacks.top(); stacks.pop();
        v.push_back({st1.second + 1, st2.second + 1});
        if (st1.first - 1 > 0) stacks.push({st1.first - 1, st1.second});
        if (st2.first - 1 > 0) stacks.push({st2.first - 1, st2.second});
    }
    cout << "yes" << endl;
    for(auto &i : v)
        cout << i.first << " " << i.second << endl;
    return 0;
}
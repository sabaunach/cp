#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<double, double>> v(n);
    for(int i= 0;i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    double ret = 0;
    for(int i = 0; i < n-1; i++){
        ret = max(ret, abs(v[i+1].second-v[i].second)/abs(v[i+1].first-v[i].first));
    }
    cout << setprecision(1000) << ret << endl;
}
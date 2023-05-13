#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i<(b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)((x).size())
typedef long long ll;
typedef vector<int> vi;

unordered_map<ll, ll> P;
unordered_map<ll, set<ll>> T;


void cdft(ll d){
    if(T.count(d)){
        for(ll i : T[d]){
            cdft(i);
        }
        T.erase(d);
    }
}

void walk(ll p, ll c){
    vector<set<ll>::iterator> v;
    for (auto it = T[p].begin(); it != T[p].end() && *it < c; it++) {
        v.push_back(it);
    }
    for (auto &it: v) cdft(*it);
    if (v.front() != T[p].end())
        T[p].erase(v.front(), next(v.back()));
    if(P[p]){
        walk(P[p], p);
        P[p] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, m; cin >> n >> m;
    rep(i,1,n+1) T[i] = {0, {}};
    rep(i,1,n){
        ll a, b; cin >> a >> b;
        T[a].insert(b);
        P[b] = a;
    }
    rep(i,0,m){
        ll d; cin >> d;
        if(T.count(d)){
            walk(P[d], d);
        }else{
            cout << i << endl;
            return 0;
        }
    }
    cout << m << endl;
    return 0;
}
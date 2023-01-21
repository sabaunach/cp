#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //long long mod = 1e9+7;
    long long ret = 0, ones = 0, twos = 0, mod = 1e9+7, n, toadd = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(auto &i : v){
        if(i == 1) ones++;
        else if(i == 2) {
            toadd = (2 * toadd + ones) % mod;
        }
        else{
            ret = (ret + toadd) % mod;
        }
    }
    cout << ret << endl;
    return 0;
}
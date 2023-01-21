#include <bits/stdc++.h>
#include <numeric>

#define int unsigned long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int t;
    vector<int> coeff;
    for(int i = 0; i < n; i++){
        cin >> t;
        coeff.push_back(t);
    }
    reverse(coeff.begin(),coeff.end());
    int denom = coeff[0];
    int num = 1;
    for(int i = 1; i < n; i++){
        num = coeff[i]*denom+num;
        int temp = denom;
        denom = num;
        num = temp;
    }
    int32_t g = gcd(num,denom);
    if(g != 1){
        num /= g;
        denom /= g;
    }

    cout << denom << "/" << num;
}
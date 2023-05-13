#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first
#define se second

typedef pair<int, int> pii;

#define UMAX(a,b) a = max(a,b)
#define UMIN(a,b) a = min(a,b)

int main() {
    // all numbers L <= limit
    // L <= 5*10^11
    // 5*10^22 = (p_1)^2*(p_2)^4*(p_3)^4
    //

    ll L = 5e11;
    int N = 3e6;
    vector<ll> primes_1, primes_2;
    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            if (i % 3 == 1) primes_1.push_back(i);
            if (i % 3 == 2) primes_2.push_back(i);
            for (int j = i+i; j < N; j += i)
                isPrime[j] = false;
        }
    }


    set<ll> pp;
    auto ppins = [&] (ll x) { if (x <= L*L) return pp.insert(x), true; return false; };
    for (int i = 0; i < primes_1.size(); i++) {
        cout << i << endl;
        if (i%100) cout << i << endl;
        auto p1 = primes_1[i];
        cout << L*L << endl;
        if (p1*p1*p1*p1*primes_1[i+1]*primes_1[i+1] > L*L) break;
        for (int j = i+1; j < primes_2.size(); j++) {
            auto p2 = primes_1[j];
            if (p1*p1*p1*p1*p2*p2 > L*L) break;
            for (int k = j+1; k < primes_2.size(); k++) {
                auto p3 = primes_1[k];
                if (p1*p1*p1*p1*p2*p2*p2*p2*p3*p3 > L*L)
                    break;
                ppins(p1*p1*p2*p2*p2*p2*p3*p3*p3*p3);
                ppins(p1*p1*p1*p1*p2*p2*p3*p3*p3*p3);
                ppins(p1*p1*p1*p1*p2*p2*p2*p2*p3*p3);
                for (auto &[a,b]: vector<pair<int,int>>{{p1,p2},{p2,p1},{p1,p3},{p3,p1},{p2,p3},{p3,p2}}) {
                    if (24*log(b) < log(L*L))
                        ppins(a*a*pow(b,24));
                    if (14*log(b) < log(L*L))
                        ppins(a*a*a*a*pow(b, 14));
                }
            }
        }
    }
    cout << pp.size() << endl;

    //
}
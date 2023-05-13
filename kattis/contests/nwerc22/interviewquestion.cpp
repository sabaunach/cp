#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> primes;
    vector<bool> isp(100001,true);
    for(int i = 2; i <= 100000; i++) {
        if (!isp[i]) continue;
        primes.push_back(i);
        for(int j = i*i; j < 100000; j++)
            isp[j] = false;
    }

    int c,d; cin >> c >> d;
    bitset<100001> a;
    bitset<100001> b;

    for(int i = c; i <= d; i++) {
        string s; cin >> s;
        bool fizz = s[0] == 'F', buzz = s[s.size()-3] == 'u';
        for(int f = 1; f*f <= i; f++) {
           if (fizz ^ (i%f == 0))
               a[f] = a[i/f] = 1;
           if (buzz ^ (i%f == 0))
               b[f] = b[i/f] = 1;
        }
    }
    for(int i = 1; i <= 100001; i++)
        if (!a[i]) {
            cout << i;
            break;
        }
    cout << " ";
    for(int i = 1; i <= 100001; i++)
        if (!b[i]) {
            cout << i;
            break;
        }

}
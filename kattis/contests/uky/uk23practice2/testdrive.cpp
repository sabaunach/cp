#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c; cin >> a >> b >> c;
    if ((b-a)*(c-b)<0) cout << "turned";
    else if (abs(c-b)>abs(b-a)) cout << "accelerated";
    else if (abs(c-b)<abs(b-a)) cout << "braked";
    else cout << "cruised";
}
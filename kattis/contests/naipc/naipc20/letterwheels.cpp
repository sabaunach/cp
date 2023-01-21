#include <bits/stdc++.h>

using namespace std;

int n;

bool isOpposite(const string& a, int aRotate, const string& b, int bRotate = 0) {
    for (int i = 0; i < n; i++)
        if (a[n + i + aRotate] == b[n + i + bRotate])
            return false;
    return true;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    string a, b, c;
    cin >> a >> b >> c;
    n = a.length();

    a += a + a;
    b += b + b;
    c += c + c;

    vector<int> rotationsa_bV; // valid rotations to get a and b to work [-500,499]
    // try rotations of a compared to b
    if (isOpposite(a, 0, b))
        rotationsa_bV.push_back(0);
    for (int i = 1; i <= (n+1)/2; i++) {
        if(isOpposite(a, i, b))
            rotationsa_bV.push_back(i);
        if(isOpposite(a, -i, b))
            rotationsa_bV.push_back(-i);
    }

    cout << rotationsa_bV.size();
    // try rotations of c compared to a and b
    for (int r: rotationsa_bV) {
        if(isOpposite(c, 0, a, r) && isOpposite(c, 0, b)) {
            cout << abs(r);
            return 0;
        }
    }

    for (int i = 1; i <= (n+1)/2; i++) {
        for (int r: rotationsa_bV) {
            if(isOpposite(c, i, a, r) && isOpposite(c, i, b)) {
                cout << abs(r) + abs(i);
                return 0;
            }
            if(isOpposite(c, -i, a, r) && isOpposite(c, -i, b)) {
                cout << abs(r) + abs(i);
                return 0;
            }
        }
    }
    cout << -1;
}

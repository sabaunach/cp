#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
typedef long long ll;

struct frac {
    ll n, d; frac() {} frac(ll n, ll d) : n(n), d(d) {}
    frac simplify(const frac &a) const { ll g = gcd(a.n, a.d); return {a.n / g, a.d / g}; }
    frac operator+(const frac &a) const { ll l = lcm(d, a.d); return simplify({n * (l / d) + a.n * (l / a.d), l}); }
    frac operator*(const frac &a) const { return simplify({n * a.n, d * a.d}); }
    frac operator-(const frac &a) const { return *this + frac(-1*a.n, a.d);  }
    frac operator/(const frac &a) const { if (a.n == 0) throw runtime_error("divide by 0"); return *this * frac(a.d, a.n); }
    double val() const { return (double)n / d; }
};
ostream & operator<<(ostream & s, const frac & a) { return s << (to_string(a.n) + "/" + to_string(a.d)); }

const int MAXN = 9999999;
bool vis[MAXN];
vector<frac> p;

int pck(int twos, int ones, int zeros) {
    return (twos*18+ones)*34+zeros;
}

int M, N, P;

frac dfs(int twos, int ones, int zeros) {
    if (ones < 0) return {0, 1};
    if (zeros > M - 2*N) return {0, 1};

    int state = pck(twos, ones, zeros);
    if (vis[state]) return p[state];
    vis[state] = true;
    int covered = twos + ones;
    if (twos*2 + ones + zeros == P) {
        if (covered == N)
            return p[state] = {1,1};
        return p[state] = {0,1};
    }
    if (covered == N) return p[state] = {0, 1};

    frac totp = {0, 1}; int totn = 0; int ways;

    ways = M - 2*N - zeros;
    totn += ways;
    totp = totp + dfs(twos, ones, zeros + 1) * frac({ways, 1});

    ways = ones;
    totn += ways;
    totp = totp + dfs(twos + 1, ones - 1, zeros) * frac({ways, 1});

    ways = 2*(N - covered);
    totn += ways;
    totp = totp + dfs(twos, ones + 1, zeros) * frac({ways, 1});

    totp = totp * frac({1, totn});
    return p[state] = totp;
}

int main() {
    cout << frac(1, 2) / frac(0, 1);
    cin >> M >> N >> P;
    p.resize(MAXN);
    cout << dfs(0,0,0);
}
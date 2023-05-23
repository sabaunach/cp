#include <bits/stdc++.h>
using namespace std;
	
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> mat;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

template <class T1, class T2>
istream& operator>>(istream& is, pair<T1,T2>& p) {
	return is >> p.first >> p.second;
}

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<class T>
istream& operator>>(istream& is, vector<T>& v) {
	for(auto& i : v) is >> i;
	return is;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for(auto& i : v) os << i << " ";
	return os;
}

#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
#define sz(c) int(c.size())

#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define rep(i,s,e) for(int i = (s); i < (e); i++)
#define repd(i,s,e) for(int i = (s); i > (e); i--)
#define repn rep(i,0,n)
#define fore(i,c) for (auto& i : (c))

#define R(x) int x; cin >> x
#define RL(x) ll x; cin >> x
#define RD(x) double x; cin >> x
#define RS(x) string x; cin >> x

#define RV(x,n) vi x(n); cin >> x
#define RVL(x,n) vll x(n); cin >> x
#define RVD(x,n) vd x(n); cin >> x
#define RVS(x,n) vs x(n); cin >> x

#define RN R(n)
#define RNV R(n); RV(v,n)
#define RNVL R(n); RVL(v,n)

#define UMIN(a,b) (a) = min((a), (b))
#define UMAX(a,b) (a) = max((a), (b))
#define CHMIN(a,b) (((a) = min((a),(b))) == b)
#define CHMAX(a,b) (((a) = max((a),(b))) == b)

#define T(args...) [args]

typedef vector<double> vd;
const double eps = 1e-12;

int solveLinear(vector<vd>& A, vd& b, vd& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		double v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = fabs(A[r][c])) > bv)
				br = r, bc = c, bv = v;
		if (bv <= eps) {
			rep(j,i,n) if (fabs(b[j]) > eps) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = 1/A[i][i];
		rep(j,i+1,n) {
			double fac = A[j][i] * bv;
			b[j] -= fac * b[i];
			rep(k,i+1,m) A[j][k] -= fac*A[i][k];
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] /= A[i][i];
		x[col[i]] = b[i];
		rep(j,0,i) b[j] -= A[j][i] * b[i];
	}
	return rank; // (multiple solutions if rank < m)
}
        
void solve() {
    int n; cin >>n;
    vector<vd> A(3,vd(n));
    cin >> A[0] >> A[1];
    // cout<<A<<endl;
    rep(i,0,n) A[2][i] = 1;
    vd s(2); cin >> s;
    s.pub(1);
    // cout<<s<<endl;
    vd x(n);
    int r = solveLinear(A,s,x);
    bool b = true;
    fore(d,x) if (d < 0 || d > 1) b=false;
    if (r==-1 || !b) cout << "No\n";
    else {
    	cout << "Yes\n";
    	fore(d,x) cout << fixed << setprecision(10) << d << " ";
    	cout << endl;
    }
}
 
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    // int t; cin >> t; while(t--)
    // while (1)
    solve();
}
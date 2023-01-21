#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,K;

struct pt {
	ll x, y;
	pt() : x(0), y(0) {}
	pt(ll _x, ll _y) : x(_x), y(_y) {}
	pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
	pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
	pt operator*(ll s) const { return pt(x*s, y*s); }
	ll cross(const pt &p) const { return x * p.y - y * p.x; }
	ll dot(const pt &p) const { return x * p.x + y * p.y; }
	ll cross(const pt &a, const pt &b) const { return (a - *this).cross(b - *this); }
	ll dot(const pt &a, const pt &b) const { return (a - *this).dot(b - *this); }
	ll sqrLen() const { return this->dot(*this); }
	bool operator<(const pt &p) const { return x < p.x || (x == p.x && y < p.y); }
};

int sgn(ll val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }

int orientation(pt a, pt b, pt c) { return sgn(a.cross(b,c)); }

bool cw(pt a, pt b, pt c, bool include_collinear) {
	int o = orientation(a, b, c);
	return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

bool inter1(ll a, ll b, ll c, ll d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}

// returns if 2 line segments intersect
bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
	if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
		return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
	return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
		   sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

bool check_parallel(pt d1, pt d2) {
	return d1.cross(d2) == 0;
}

// returns the point where 2 lines intersect
// a is point on line, d is direction
double inter_tval(pt a1, pt d1, pt a2, pt d2) {
    return 1.0 * (a2-a1).cross(d2) / d1.cross(d2);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
	pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
		return make_pair(a.y, a.x) < make_pair(b.y, b.x);
	});
	sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
		int o = orientation(p0, a, b);
		if (o == 0)
			return p0.dot(a) < p0.dot(b);
		return o < 0;
	});
	if (include_collinear) {
		int i = (int)a.size()-1;
		while (i >= 0 && collinear(p0, a[i], a.back())) i--;
		reverse(a.begin()+i+1, a.end());
	}

	vector<pt> st;
	for (int i = 0; i < (int)a.size(); i++) {
		while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
			st.pop_back();
		st.push_back(a[i]);
	}

	a = st;
}

vector<pt> seq, sights;
int n;

bool intersect(vector<pt> &pts, int s, int e, pt x0, pt x1) {
	n = e - s;
	if (n == 2)
		return check_inter(pts[s], pts[(s+1)%K], x0, x1);
	if (n == 3)
		return check_inter(pts[s], pts[(s+1)%K], x0, x1)
			|| check_inter(pts[(s+1)%K], pts[(s+2)%K], x0, x1)
			|| check_inter(pts[(s+2)%K], pts[s], x0, x1);

	pt v0 = pts[s], vmid = pts[(s + n/2) % K];
	pt dv = vmid - v0, dx = x1 - x0;
	bool parallel = check_parallel(dv, dx);
	if (parallel) {
		int o = orientation(v0, vmid, x0);
		if (o < 0) {
			// auto first = pts.begin() + n/2;
			// auto last = pts.end();
			// vector<pt> subpts(first, last);
			// subpts.push_back(v0);
			return intersect(pts, (s+n/2)%K, s+1 + (s+n/2 < K ? K : 0), x0, x1);
		} else {
			// auto first = pts.begin();
			// auto last = pts.begin() + (n/2 + 1);
			// vector<pt> subpts(first, last);
			return intersect(pts, s, s+n/2+1, x0, x1);
		}
	} else {
		double inter_t = inter_tval(v0, dv, x0, dx);
		pt v1 = pts[(s+1)%K], vmidp1 = pts[(s+n/2 + 1)%K];
		if (0 <= inter_t && inter_t <= 1) return true;
		else if (inter_t < 0) {
			parallel = check_parallel(v1 - v0, dx);
			if (parallel) return false;
			double inter_t2 = inter_tval(v0, v1-v0, x0, dx);
			if (inter_t2 > 0) {
				// auto first = pts.begin();
				// auto last = pts.begin() + (n/2 + 1);
				// vector<pt> subpts(first, last);
				return intersect(pts, s, s+n/2+1, x0, x1);
			} else {
				// auto first = pts.begin() + n/2;
				// auto last = pts.end();
				// vector<pt> subpts(first, last);
				// subpts.push_back(v0);
				return intersect(pts, (s+n/2)%K, s+1 + (s+n/2 < K ? K : 0),x0, x1);
			}
		} else {
			parallel = check_parallel(vmidp1 - vmid, dx);
			if (parallel) return false;
			double inter_t2 = inter_tval(vmid, vmidp1-vmid, x0, dx);
			if (inter_t2 < 0) {
				// auto first = pts.begin();
				// auto last = pts.begin() + (n/2 + 1);
				// vector<pt> subpts(first, last);
				return intersect(pts, s, s+n/2+1, x0, x1);
			} else {
				// auto first = pts.begin() + n/2;
				// auto last = pts.end();
				// vector<pt> subpts(first, last);
				// subpts.push_back(v0);
				return intersect(pts, (s+n/2)%K, s+1 + (s+n/2 < K ? K : 0),x0, x1);
			}
		}
	}

	return 0;
}

int nextToRight(int i) {
	pt p = seq[i];
	int l = i, r = i + N - 1, mid;
	while (r - l > 1) {
		mid = (l + r) / 2;
		// cout << l << " " << r << " " << mid << endl;
		// cout << intersect(sights, seq[i], seq[mid % N]) << endl;
		if (intersect(sights, 0, K, seq[i], seq[mid % N]) || orientation(seq[i], seq[mid % N], sights[0]) > 0)
			r = mid;
		else
			l = mid;
	}
	// cout << l%N << " ";
	return l%N;
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for(int i = 0, x, y; i < N; i++) {
		cin >> x >> y;
		seq.emplace_back(x,y);
	}

	if (orientation(seq[0], seq[1], seq[2]) > 0) reverse(seq.begin(), seq.end());

	cin >> K;
	for(int i = 0, x, y; i < K; i++) {
		cin >> x >> y;
		sights.emplace_back(x,y);
	}

	convex_hull(sights);
	K = sights.size();
	
	unordered_map<int, int> vis;
	int ans = 1, ni = 0;
	vis[0] = 0;
	while (true) {
		ni = nextToRight(ni);
		if (vis.find(ni) == vis.end()) {
			vis[ni] = ans++;
		} else {
			cout << ans - vis[ni] << endl;
			break;
		}
	}

	// int nxt = nextToRight(7);
	// cout << seq[nxt].x<<" "<<seq[nxt].y;

	return 0;
}
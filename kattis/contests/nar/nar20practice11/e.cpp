#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct Point{
	typedef Point Vector;
	ll x, y;
	Point() {}
	Point(ll x, ll y) : x(x), y(y) {}
	bool operator<(const Point &rhs) const{
		return make_pair(x,y) < make_pair(rhs.x,rhs.y);
	}
	Vector operator-(const Point &rhs) const{
		return Vector(x - rhs.x, y  - rhs.y);
	}
	ll operator*(const Point & rhs) const {
		return x*rhs.y - y * rhs.x;
	}
} Vector;

vector<Point> convex_hull(vector<Point> v){
	sort(v.begin(), v.end());
	int k = 0, n = v.size();
	vector<Point> ret(n*2);
	for(int i = 0; i < n; i++){
		while(k > 1 && (ret[k-1] - ret[k-2]) * (v[i]-ret[k-1]) <= 0) k--;
		ret[k++] = v[i];
	}
	for(int i = n-2, t = k; i >= 0; i--){
		while(k > t && (ret[k-1] - ret[k-2]) * (v[i] - ret[k-1]) <= 0) k--;
		ret[k++] = v[i];
	}
	ret.resize(k-1);
	return ret;
}

ll area(Point a, Point b, Point c){
	return (a-b) * (b-c);
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<Point> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].x >> v[i].y;
	}
	vector<Point> ps = convex_hull(v);
	double ans = 0;
	if(ps.size() > 2){
		for(int i = 0; i < ps.size(); i++){
			int k = i+2;
			for(int j = i+1; j < ps.size(); j++){
				while(k+1 < ps.size() && area(ps[i],ps[j],ps[k]) < area(ps[i],ps[j],ps[k+1])) k++;
				ans = max(ans, 0.5*area(ps[i], ps[j], ps[k]));
			}
		}
	}
	cout << setprecision(15) << ans << endl;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, a, b, c;
	pair<int,int> t;
	unordered_map<int, unordered_map<int,int> > v;
	cin >> n >> m;
	for(int i  = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a][b] = c;
		v[b][a] = c;
	}
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push({0,1});
	unordered_map<int,int> ma;
	unordered_set<int> s;
	ma[1] = -1;
	s.insert(1);
	bool bad = true;
	while(!pq.empty()) {
		t = pq.top();
		pq.pop();
		s.insert(t.second);
		if(t.second == 0) {
			bad = false;
			break;
		}
		for(auto &i : v[t.second]) {
			if(s.find(i.first) == s.end()) {
				pq.push({t.first+i.second, i.first});
				ma[i.first] = t.second;
			}
		}
	}
	if(bad) {
		cout << "impossible" << endl;
		return 0;
	}
	int curr = 0;
	vector<int> r, ret;
	while(curr != -1) {
		r.push_back(curr);
		curr = ma[curr];
	}
	/*for(int i = 1; i < r.size(); i++){
	    v[r[i]].erase(r[i-1]);
	    v[r[i-1]].erase(r[i]);
	   }*/
	if(r.size() == 2) {
		v[0].erase(1);
		v[1].erase(0);
	}
	for(int i = 1; i < r.size()-1; i++) {
		v.erase(r[i]);
	}
	if(v.size() == 2) {
		cout << "impossible" << endl;
		return 0;
	}
	pq = priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >();
	pq.push({0,0});
	ma.clear();
	s.clear();
	ma[0] = -1;
	s.insert(0);
	bad = true;
	while(!pq.empty()) {
		t = pq.top();
		pq.pop();
		s.insert(t.second);
		if(t.second == 1) {
			bad = false;
			break;
		}
		for(auto &i : v[t.second]) {
			if(s.find(i.first) == s.end()) {
				pq.push({t.first+i.second, i.first});
				ma[i.first] = t.second;
			}
		}
	}
	if(bad) cout << "impossible" << endl;
	else{
		int curr = 1;
		while(curr != -1) {
			ret.push_back(curr);
			curr = ma[curr];
		}
		reverse(ret.begin(), ret.end());
		cout << ret.size() << " ";
		for(auto &i : ret) cout << i << " ";
		cout << endl;
	}
	return 0;
}

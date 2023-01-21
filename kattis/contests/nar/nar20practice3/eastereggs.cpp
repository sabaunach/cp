#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, b, r;
	cin >> n >> b >> r;
	vector<pair<double, double> > bbps;
	vector<pair<double, double> > rbps;
	for (int i = 0; i < b; i++) {
		double x, y; cin >> x >> y;
		bbps.push_back({x,y});
	}
	for (int i = 0; i < r; i++) {
		double x, y; cin >> x >> y;
		rbps.push_back({x,y});
	}

	vector<tuple<double, int, int> > dists;
	for (int i = 0; i < bbps.size(); i++) {
		auto bx_y = bbps[i];
		for (int j = 0; j < rbps.size(); j++) {
			auto rx_y = rbps[j];
			dists.push_back({sqrt((bx_y.second - rx_y.second) * (bx_y.second - rx_y.second)
			                      + (bx_y.first - rx_y.first) * (bx_y.first - rx_y.first)),
			                 i, j});
		}
	}

	unordered_map<int, unordered_set<int> > remaining_br;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < r; j++) {
			remaining_br[i].insert(j);
		}
	}
	unordered_map<int, unordered_set<int> > remaining_rb;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < b; j++) {
			remaining_rb[i].insert(j);
		}
	}
	sort(dists.begin(), dists.end(), std::greater<tuple<double, int, int> >());

	while (remaining_br.size() + remaining_rb.size() > n) {
		auto dist = dists.back(); dists.pop_back();
		int blue = get<1>(dist);
		int red = get<2>(dist);

		// if would cause number of bushes to go below n ?

		remaining_br[blue].erase(red);
		if (remaining_br[blue].size() == 0)
			remaining_br.erase(blue);
		remaining_rb[red].erase(blue);
		if (remaining_rb[red].size() == 0)
			remaining_rb.erase(red);
	}
	cout << setprecision(15);
	cout << get<0>(dists.back());
}

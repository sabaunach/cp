#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

struct state {
	int price;
	int b;
	int daysHeld;

};

struct compareState {
	bool operator()(const state& a, const state& b) const {
		return a.price > b.price;
	}
};

int main() {
	vector<int> p;
	vector<int> d;
	int l, t, n;

	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> n;
		p.push_back(n);
	}
	for (int i = 0; i < l - 1; i++) {
		cin >> n;
		d.push_back(n);
	}
	d.push_back(100001);

	cin >> t >> n;

	vector<int> breakBegins;
	vector<int> breakEnds;

	while (n--) {
		int b, e;
		cin >> b >> e;
		breakBegins.push_back(b);
		breakEnds.push_back(e);
	}
	breakBegins.push_back(t + 1); // maybe offbyone

	// precompute price for keeping pass over interval of n days
	vector<int> a = {0};
	int daysLeft = d[0];
	int icurPrice = 0;
	for (int i = 1; i <= t; i++) {
		a.push_back(a[i - 1] + p[icurPrice]);
		daysLeft--;
		if (daysLeft == 0) {
			icurPrice++;
			daysLeft = d[icurPrice];
		}
	}

	state start;
	start.b = 0;
	start.daysHeld = breakBegins[0] - 1;
	start.price = a[start.daysHeld];
	vector<state> openSet = {start};

	auto compare = [](state lhs, state rhs)
				   {
					   return lhs.price < rhs.price;
				   };

	if (breakEnds.size() == 0) {
		cout << start.price;
		return 0;
	}
	while(!openSet.empty()) {
		// expand node with min position on heap

		state s = openSet.back();
		pop_heap(openSet.begin(), openSet.end(), compare);
		openSet.pop_back();

		/*cout << "EXPANDING STATE:";
		   cout << "\n  b = " << s.b;
		   cout << "\n  daysHeld = " << s.daysHeld;
		   cout << "\n  price = " << s.price;
		   cout << "\n";*/

		int breakLength = (breakEnds[s.b] - breakBegins[s.b]) + 1;
		int inLength = (breakBegins[s.b + 1] - breakEnds[s.b]) - 1;
		// if holding pass through break
		state hold;
		hold.b = s.b + 1;
		hold.daysHeld = s.daysHeld + breakLength + inLength;
		hold.price = s.price + a[s.daysHeld + breakLength + inLength] - a[s.daysHeld];
		// if letting go of pass through break
		state letGo;
		letGo.b = s.b + 1;
		letGo.daysHeld = inLength;
		letGo.price = s.price + a[inLength];

		if (s.b + 1 == breakEnds.size()) {
			// last iteration!
			cout << min(hold.price, letGo.price);
			return 0;
		}

		openSet.push_back(hold);
		push_heap(openSet.begin(), openSet.end(), compare);
		openSet.push_back(letGo);
		push_heap(openSet.begin(), openSet.end(), compare);
	}

	cout << "error somewhere!";
}

#include <bits/stdc++.h>

using namespace std;

int main() {
	// start with no segments added
	// add each segment
	// for each segment, keep track of adjacent #s that would complete segment
	// for each segment, keep sum
	// keep running total chaos, modify at each step based on segments added

	int n; cin >> n;
	vector<int> passengers(n + 2, 0);

	for (int i = 1; i <= n; i++) {
		int p; cin >> p;
		passengers[i] = p;
	}

	vector<int> seg_l(n + 2, -1);
	vector<int> seg_satis_l(n + 2, -1);
	vector<int> seg_r(n + 2, -1);
	vector<int> seg_satis_r(n + 2, -1);
	vector<int> seg_chaos_sums(n + 2, 0);
	vector<int> seg_passengers_sums(n + 2, 0);
	int total = 0;
	int maxt = 0;

	vector<int> blownUp;

	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		blownUp.push_back(c);
	}

	reverse(blownUp.begin(), blownUp.end());

	int numSegs = 0;
	int i = 0;
	for (int c: blownUp) {
		i++;
		if (seg_l[c] == -1 && seg_r[c] == -1) {
			// add new segment
			seg_passengers_sums[i] = passengers[c];
			seg_chaos_sums[i] = ((seg_passengers_sums[i] + 9) / 10) * 10;

			seg_l[c - 1] = i;
			seg_satis_l[i] = c - 1;
			seg_r[c + 1] = i;
			seg_satis_r[i] = c + 1;

			// redo total
			if (numSegs > 0)
				total /= numSegs;
			total += seg_chaos_sums[i];
			numSegs++;
			total *= numSegs;
		}
		else if (seg_l[c] != -1 && seg_r[c] != -1) {
			// merge two segments
			int right = seg_l[c]; int left = seg_r[c];
			seg_passengers_sums[i] = seg_passengers_sums[left] + passengers[c] + seg_passengers_sums[right];
			seg_chaos_sums[i] = ((seg_passengers_sums[i] + 9) / 10) * 10;

			seg_l[seg_satis_l[left]] = i;
			seg_satis_l[i] = seg_satis_l[left];
			seg_r[seg_satis_r[right]] = i;
			seg_satis_r[i] = seg_satis_r[right];

			// redo total
			if (numSegs > 0)
				total /= numSegs;
			total += seg_chaos_sums[i] - seg_chaos_sums[right] - seg_chaos_sums[left];
			numSegs--;
			total *= numSegs;

		} else if (seg_l[c] != -1) {
			// add to left of segment
			int right = seg_l[c];
			seg_passengers_sums[i] = passengers[c] + seg_passengers_sums[right];
			seg_chaos_sums[i] = ((seg_passengers_sums[i] + 9) / 10) * 10;
			seg_l[c - 1] = i;
			seg_satis_l[i] = c - 1;
			seg_r[seg_satis_r[right]] = i;
			seg_satis_r[i] = seg_satis_r[right];

			// redo total
			if (numSegs > 0)
				total /= numSegs;
			total += seg_chaos_sums[i] - seg_chaos_sums[right];
			total *= numSegs;
		} else if (seg_r[c] != -1) {
			// add to right of segment
			int left = seg_r[c];
			seg_passengers_sums[i] = seg_passengers_sums[left] + passengers[c];
			seg_chaos_sums[i] = ((seg_passengers_sums[i] + 9) / 10) * 10;
			seg_l[seg_satis_l[left]] = i;
			seg_satis_l[i] = seg_satis_l[left];
			seg_r[c + 1] = i;
			seg_satis_r[i] = c + 1;

			// redo total
			if (numSegs > 0)
				total /= numSegs;
			total += seg_chaos_sums[i] - seg_chaos_sums[left];
			total *= numSegs;
		}
		maxt = max(total, maxt);
	}
	cout << maxt;
}

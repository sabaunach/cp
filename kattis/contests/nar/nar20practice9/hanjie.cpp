#include <bits/stdc++.h>

using namespace std;

bool validateRow(vector<bool> row, vector<int> hint, int n) {
	int block = 0, i = 0;
	for (; i < n; i++) {
		if (row[i]) {
			for (int j = 0; i < n && j < hint[block]; i++, j++) {
				if (!row[i])
					return false;
			}

			if (i < n && row[i])
				return false;
			block++;
		}
	}
	if (block < hint.size())
		return false;
	return true;
}

vector<vector<bool> > generateRows(vector<int> hint, int sum, int n) {
	// all permutations with sum number of black tiles
	vector<vector<bool> > rows;
	vector<bool> row(n);
	for (int i = 0; i < sum; i++) {
		row[i] = 1;
	}
	do {
		if (validateRow(row, hint, n))
			rows.push_back(row);
	} while (prev_permutation(row.begin(), row.end()));
	return rows;
}

bool nextState(vector<int> & curState, const vector<vector<vector<bool> > > & rows) {
	int i = curState.size() - 1;
	for (; i >= 0; i--) {
		if (curState[i] < rows[i].size() - 1) {
			curState[i] += 1;
			for (int j = i + 1; j < curState.size(); j++) {
				curState[j] = 0;
			}
			break;
		}
	}
	if (i == -1)
		return false;
	return true;
}

bool isValidState(vector<int> curState, vector<vector<vector<bool> > > allRows, vector<vector<int> > hintC) {
	// generate columns
	vector<vector<bool> > cols(hintC.size(), vector<bool>(allRows[0][0].size()));
	for (int i = 0; i < curState.size(); i++) {
		for (int j = 0; j < (allRows[i][curState[i]]).size(); j++) {
			cols[j][i] = (allRows[i][curState[i]])[j];
		}
	}
	for (int i = 0; i < cols.size(); i++) {
		if (!validateRow(cols[i], hintC[i], cols[i].size()))
			return false;
	}
	return true;
}

// 0: white, 1: black
int main() {
	int r, c; cin >> r >> c;
	vector<vector<int> > hintR(r);
	vector<vector<int> > hintC(c);
	vector<int > sumR(r);
	vector<int > sumC(c);
	for (int i = 0; i < r; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			hintR[i].push_back(a);
			sumR[i] += a;
		}
	}
	for (int i = 0; i < c; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			hintC[i].push_back(a);
			sumC[i] += a;
		}
	}
	vector<vector<vector<bool> > > allRows(r);
	for (int i = 0; i < r; i++) {
		allRows[i] = generateRows(hintR[i], sumR[i], c);
	}
	vector<int> curState(r, 0);
	int cnt = 0;
	do {
		if (isValidState(curState, allRows, hintC)) {
			cnt++;
			/*for (int row = 0; row < allRows.size(); row++) {
			    for (int b = 0; b < c; b++) {
			        cout << allRows[row][curState[row]][b] << " ";
			    }
			    cout << "\n";
			   }
			   cout << "\n\n";*/
		}
	} while (nextState(curState, allRows));
	cout << cnt << "\n";
}

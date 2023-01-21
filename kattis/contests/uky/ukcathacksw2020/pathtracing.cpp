#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	vector<int> moves; // 0=l 1=r 2=d 3=u
	string s;
	while (cin >> s) {
		if (s == "left")
			moves.push_back(0);
		else if (s == "right")
			moves.push_back(1);
		else if (s == "down")
			moves.push_back(2);
		else if (s == "up")
			moves.push_back(3);
	}

	int downmax = 0, upmin = 0, leftmin = 0, rightmax = 0;
	int vertpos = 0, horzpos = 0;
	for (int move: moves) {
		switch(move) {
		case 0:
			horzpos--;
			if (horzpos < leftmin)
				leftmin = horzpos;
			break;
		case 1:
			horzpos++;
			if (horzpos > rightmax)
				rightmax = horzpos;
			break;
		case 2:
			vertpos++;
			if (vertpos > downmax)
				downmax = vertpos;
			break;
		case 3:
			vertpos--;
			if (vertpos < upmin)
				upmin = vertpos;
			break;
		}
	}
	// cout << downmax << " " << upmax << " " << leftmax << " " << rightmax;
	int width = abs(leftmin) + rightmax + 1;
	int height = downmax + abs(upmin) + 1;
	vector<vector<char> > board(height, vector<char>(width, ' '));
	vertpos = abs(upmin);
	horzpos = abs(leftmin);
	board[vertpos][horzpos] = 'S';
	for (int move: moves) {
		switch(move) {
		case 0:
			horzpos--;
			break;
		case 1:
			horzpos++;
			break;
		case 2:
			vertpos++;
			break;
		case 3:
			vertpos--;
			break;
		}
		if (board[vertpos][horzpos] != 'S')
			board[vertpos][horzpos] = '*';
	}
	board[vertpos][horzpos] = 'E';
	for (int i = -1; i < width + 1; i++) {
		cout << '#';
	}
	cout << "\n";
	for (int i = 0; i < height; i++) {
		cout << '#';
		for (char c: board[i])
			cout << c;
		cout << "#\n";
	}
	for (int i = -1; i < width + 1; i++) {
		cout << "#";
	}
	cout << "\n";
}

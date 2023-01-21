#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	string s;
	while(true) {
		cin >> s;
		if (s == "end") {
			cout << "end\n";
			return 0;
		}

		vector<int> numbers;
		for (char c: s) {
			if (c != ':')
				numbers.push_back(c - 48);
		}

		for (int line = 1; line <= 7; line++) {

			for (int i = 0; i < 4; i++) {

				if (i == 2) {
					if (line == 3 || line == 5)
						cout << "o  ";
					else
						cout << "   ";
				}

				switch(numbers[i]) {
				case 0:
					if (line == 1 || line == 7)
						cout << "+---+";
					else if (line == 4)
						cout << "+   +";
					else
						cout << "|   |";
					break;

				case 1:
					if (line == 1 || line == 4 || line == 7)
						cout << "    +";
					else
						cout << "    |";
					break;

				case 2:
					if (line == 1 || line == 4 || line == 7)
						cout << "+---+";
					else if (line < 4)
						cout << "    |";
					else
						cout << "|    ";
					break;

				case 3:
					if (line == 1 || line == 4 || line == 7)
						cout << "+---+";
					else
						cout << "    |";
					break;

				case 4:
					if (line == 1)
						cout << "+   +";
					else if (line < 4)
						cout << "|   |";
					else if (line == 4)
						cout << "+---+";
					else if (line < 7)
						cout << "    |";
					else
						cout << "    +";
					break;

				case 5:
					if (line == 1 || line == 4 || line == 7)
						cout << "+---+";
					else if (line < 4)
						cout << "|    ";
					else
						cout << "    |";
					break;

				case 6:
					if (line == 1 || line == 4 || line == 7)
						cout << "+---+";
					else if (line < 4)
						cout << "|    ";
					else
						cout << "|   |";
					break;

				case 7:
					if (line == 1)
						cout << "+---+";
					else if (line == 4 || line == 7)
						cout << "    +";
					else
						cout << "    |";
					break;

				case 8:
					if (line == 1 || line == 4 || line == 7)
						cout << "+---+";
					else
						cout << "|   |";
					break;

				case 9:
					if (line == 1 || line == 4 || line == 7)
						cout << "+---+";
					else if (line < 4)
						cout << "|   |";
					else
						cout << "    |";
					break;
				}
				if (i != 3)
					cout << "  ";

			}
			cout << "\n";
		}

		cout << "\n\n";
	}
}

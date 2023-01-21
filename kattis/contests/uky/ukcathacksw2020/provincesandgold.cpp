#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main() {
	int g, s, c;
	cin >> g >> s >> c;
	int bp = g*3 + s*2 + c;
	if (bp >= 8)
		cout << "Province or ";
	else if (bp >= 5)
		cout << "Duchy or ";
	else if (bp >= 2)
		cout << "Estate or ";
	if (bp >= 6)
		cout << "Gold";
	else if (bp >= 3)
		cout << "Silver";
	else
		cout << "Copper";
}

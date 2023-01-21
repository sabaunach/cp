#include <bits/stdc++.h>

using namespace std;

// 1 : 0, 2 : 9, 3 : 28, 4 : 28+29, 5 : 57+39, 6 : 96+49, ...
int movesToDigit[] = {0, 0, 9, 28, 57, 96, 145, 204, 273, 352, 441};

int calc(int n) {
	int total = 0;
	int numDigits = log10(n) + 1;
	total += movesToDigit[numDigits];

	int sumDigits = 0;
	int numNonZero = 0;
	int numZeros = 0;
	bool oneInMiddle = 0;
	vector<int> digits;
	for (int i = 0; i < numDigits; i++) {
		int digit = (n / (int)pow(10, i)) % 10;
		sumDigits += digit;
		if (digit != 0)
			numNonZero++;
		else
			numZeros++;
		if (digit == 1 && i > 0 && i < numDigits - 1)
			oneInMiddle = 1;
		digits.push_back(digit);
	}

	reverse(digits.begin(), digits.end());
	if (n == 1) {
		total = 0;
	} else if (numZeros == numDigits - 1 && digits[0] != 1 && numDigits > 1) {
		// edge case: # is 20, 200, 3000, etc.
		total = calc(n - 1) + 1;
	} else if (digits[0] != 1) {
		// if we do swap out first number
		// what is # swaps?
		if (digits[numDigits - 1] != 0) {
			total += sumDigits + numNonZero - 2;
		} else {
			total += sumDigits + numNonZero - 1;
		}
		if (oneInMiddle)
			total--;
	} else {
		// we don't swap out first number
		// what is # swaps?
		if (digits[numDigits - 1] != 0) {
			total += sumDigits - 1 + numNonZero - 2;
		} else {
			total += sumDigits - 1 + numNonZero - 1;
		}
		if (oneInMiddle)
			total--;
	}
	return total;
}
int main() {
	int n;
	cin >> n;
	while (cin >> n) {
		cout << calc(n) << "\n";
	}
}

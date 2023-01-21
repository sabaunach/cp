#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

vector<int> nums;

int main() {
    while (!cin.eof()) {
        string str;
        getline(cin, str, '+');
        nums.push_back(stoi(str));
    }

    for (int n: nums)
        cout << n << " ";
    cout << endl;
}

ull check(int i) {

}

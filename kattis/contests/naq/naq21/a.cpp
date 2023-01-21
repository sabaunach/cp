#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> best(string curr, set<char> unused, int n) {
    //cout << "iter: " << curr << " [";
    //for (char c: unused) cout << c << " ";
    //cout << "]" << endl;
    vector<vector<int>> final;
    if (curr.empty()) {
        final = {{numeric_limits<int>::max(), 0}};
    } else {
        final = {{abs(stoi(curr) - n), stoi(curr)}};
    }
    if (curr.length() > to_string(n).length())
        return final;
    for (char c: unused) {
        string str = curr + c;
        auto better = best(str, unused, n);
        // better has 2 optimal sols
        if (better[0][0] == final[0][0]) { final.reserve(2); final[1] = better[0]; }
        else if (better[0][0] < final[0][0]) final = better;
    }
    return final;
}

int main() {
    string in; cin >> in;
    set<char> unused = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (char c: in)
        unused.erase(c);
    int n = stoi(in);
    auto res = best("", unused, n);
    for (int i = 0; i < res.size() && i < 2; i++) {
        cout << res[i][1] << " ";
    }
}
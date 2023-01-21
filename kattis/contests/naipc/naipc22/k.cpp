#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, m;
    vector<int> song;
    vector<unordered_set<int>> notes(1001);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int note; cin >> note;
            notes[note].insert(i);
        }
    }
    for (int i = 0; i < m; i++) {
        int note; cin >> note;
        song.push_back(note);
    }

    int oo = 123456789;
    unordered_map<int, int> prevState;
    for (auto inst: notes[song[0]]) {
        prevState[inst] = 0;
    }

    int least = 0;
    for (int i = 1; i < m; i++) {
        int note = song[i];
        unordered_map<int, int> nextState;
        int nextLeast = oo;
        for (auto inst: notes[note]) {
            nextState[inst] = min(least + 1, prevState.count(inst) ? prevState[inst] : oo);
            nextLeast = min(nextLeast, nextState[inst]);
        }
        prevState = nextState;
        least = nextLeast;
    }
    cout << least;
}

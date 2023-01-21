#include <bits/stdc++.h>

using namespace std;

struct node {
    node * children[26];
    int mark;
    int n;
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int res = 0;
    node * root = new node();
    for (string s; cin >> s;) {
        node * curr = root;
        int depth = 0;
        int cmark = 0;
        for (int c = s.length() - 1; c >= 0; c--) {
            // cout << s[c];
            if (!curr->children[s[c] - 'a']) {
                curr->children[s[c] - 'a'] = new node();
                curr->n++;
                if (curr->n > 1) cmark = 0;
                curr = curr->children[s[c] - 'a'];
            } else {
                curr = curr->children[s[c] - 'a'];
                depth++;
                cmark = curr->mark;
            }
        }
        // cout << " " << curr->mark << " " << depth << endl;
        if (cmark || depth == s.length()) depth = 0;
        curr->mark = 1;
        res = max(res, depth);
    }
    cout << res;
}
#include <bits/stdc++.h>

using namespace std;

struct node {
    node *l = nullptr, *r = nullptr; int i;
    node(int i) : i(i) {}
};

int main() {
   int N; cin >> N;
   vector<vector<int>> ans(N);
   vector<int> vals(N);
   unordered_set<node*> toCheck, toRemove;
   set<int> unRemoved;
   node* root = new node(0), *curr = root;
   for (int i = 0; i < N; i++) {
       cin >> vals[i];
       toCheck.insert(curr);
       unRemoved.insert(i);
       if (i != N-1) { curr->r = new node(i+1); curr->r->l = curr; curr = curr->r; }
   }
   int cnt = 0;
   for (; !toCheck.empty(); cnt++) {
       toRemove.clear();
       for (auto n: toCheck) {
           if (n->l && vals[n->l->i] > vals[n->i] || n->r && vals[n->r->i] > vals[n->i]) {
               toRemove.insert(n);
           }
       }
       toCheck.clear();
       for (auto n: toRemove) {
           unRemoved.erase(n->i);
           ans[cnt].push_back(n->i);
           if (n->l) {
               n->l->r = n->r;
               if (!toRemove.count(n->l)) toCheck.insert(n->l);
           }

           if (n->r) {
               n->r->l = n->l;
               if (!toRemove.count(n->r)) toCheck.insert(n->r);
           }
       }
   }
   cout << cnt-1 << endl;
   for (int i = 0; i < cnt-1; i++) {
       sort(ans[i].begin(), ans[i].end());
       for (auto idx: ans[i])
           cout << vals[idx] << " ";
       cout << endl;
   }
   for (auto i: unRemoved) {
       cout << vals[i] << " ";
   }
   cout << endl;
}
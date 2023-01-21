#include <bits/stdc++.h>

using namespace std;


vector<vector<vector<double>>> mem;
int n;
double dfs(int &a, int &b, int &c) {
    int sum = a+b+c;
    if (sum == 0) return 0;
    if (mem[a][b][c] != -1) return mem[a][b][c];
    double tot = 0;
    if (a>0) { a--; tot += ((double)(a+1)/sum)*(((double)n/(sum))+(dfs(a,b,c))); a++; }
    if (b>0) { a++; b--; tot += ((double)(b+1)/sum)*(((double)n/(sum))+(dfs(a,b,c))); b++; a--; }
    if (c>0) { b++; c--; tot += ((double)(c+1)/sum)*(((double)n/(sum))+(dfs(a,b,c))); c++; b--; }
    return mem[a][b][c] = tot;
}

int main() {
    cin >> n;
    mem = vector<vector<vector<double>>>(n+1, vector<vector<double>>(n+1, vector<double>(n+1, -1)));
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) { int x; cin >> x; if (x==1) a++; else if (x==2) b++; else if (x==3) c++; }
    cout << setprecision(12) << dfs(a,b,c) << endl;
}
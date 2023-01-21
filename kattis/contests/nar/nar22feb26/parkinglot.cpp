#include <bits/stdc++.h>
using namespace std;
long long r, c;
double err;
vector<vector<double>> dists;
vector<vector<char>> v;

bool validMove(int a, int b, int i, int j){
    // invalid move
    if(i < 0 || j < 0 || i >= r || j >= c || dists[i][j] != -1) return false;
    // moving across a side
    if(abs(a-i) == 0 || abs(b - j) == 0) return true;
    // moving through squares
    double aa = a, bb = b, aAdd = abs((double)(a-i))/(10.0*abs((double)(b-j))), bAdd = 0.1, ii = i, jj = j;
    aAdd *= a-i < 0.0 ? 1.0 : -1.0;
    bAdd *= b-j < 0.0 ? 1.0 : -1.0;
    aa += aAdd;
    bb += bAdd;
    while(abs(aa - ii) > err && abs(bb - jj) > err){
        if(v[(long long)floor(aa)][(long long)floor(bb)] == '#') return false;
        aa += aAdd;
        bb += bAdd;
    }
    return true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> r >> c;
    v.resize(r, vector<char> (c));
    err = .000000001;
    dists.resize(r+1, vector<double> (c + 1, -1));
    for(long long i = 0; i < r; i++)
        for(long long j = 0; j < c; j++)
            cin >> v[i][j];
    r++, c++;
    priority_queue<pair<double, pair<long long, long long>>, vector<pair<double, pair<long long, long long>>>, greater<pair<double, pair<long long, long long>>>> pq;
    pq.push({0, {0,0}});
    pair<double, pair<long long, long long>> t;
    while(!pq.empty()){
        t = pq.top();
        pq.pop();
        double dist = t.first;
        auto[x, y] = t.second;
        if(dists[x][y] != -1) continue;
        dists[x][y] = dist;
        if(x == r-1 && y == c-1){
            cout << fixed << setprecision(9) << dist << endl;
            return 0;
        }
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                if(i == x && j == y) continue;
                if(validMove(x, y, i, j)){
                    pq.push({dist + hypot((double)(x-i), (double)(y-j)), {i,j}});
                }
            }
    }
    return 0;
}

// 1, 2 -> 3/4, 1.5 -> 1/2, 1
// 0, 0 -> 1/4, .5
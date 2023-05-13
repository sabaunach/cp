/* https://oj.uz/problem/view/IOI16_aliens
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int64_t take_photos(int n, int m, int k, int r[], int c[]) {
    // choose at most k square areas
    // minimize total # of photographed cells
    // photograph all of the points
    // n <= 100k, m <= 1m

    /*
     * X = domain of solutions
     *  -> diagonal-aligned squares
     *  -> that contain all marked cells
     *
     * f(x) = # highlighted cells
     * g(x) = # squares - k
     *
     * minimize f(x) subject to g(x) = 0
     *
     * given the cost of adding a square & the cost of each cell
     * find the total minimum cost
     * -> set up graph with potential squares & build MST?
     *   would boil down to
     *
     */


}

int main() {

}
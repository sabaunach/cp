#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << setprecision(12);
    vector<double> seq = vector<double>(50);
    seq[0] = 1.0;
    seq[1] = 4.0/5.0;
    for (int i = 2; i < n; i++) {
        seq[i] = seq[i - 1]*(4.0/5.0);
    }
    double sum = 0;
    vector<double> scores = vector<double>(50);
    for (int i = 0; i < n; i++) {
        int in; cin >> in;
        sum += in*seq[i];
        scores[i] = in;
    }
    sum *= (1.0/5.0);
    cout << sum << "\n";
    double avg = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < i; j++) {
            sum += scores[j]*seq[j];
        }
        for (int j = i+1; j < n; j++) {
            sum += scores[j]*seq[j - 1];
        }
        avg += (1.0/5.0)*sum;
    }
    avg /= n;
    cout << avg;
}

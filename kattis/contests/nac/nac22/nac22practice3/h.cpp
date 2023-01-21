#include <bits/stdc++.h>

int main() {
    int H, T;
    while (cin >> H >> T) {
        if (H == 0 && T == 0) return;
        int Tt = T, Ht = (Tt/2)+H;
        while (Ht % 2 != 0) {
            Tt += 1;
            Ht = (Tt/2)+H;
        }

    }
}
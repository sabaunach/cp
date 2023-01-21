#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2) cout << "still running\n";
    else {
        int time = 0;
        for (int i=0; i < n/2; ++i)
        {
            int a, b;
            cin >> a >> b;
            time += b - a;
        }
        cout << time << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
int s, d, r, u, v;
signed main() {
    fastIO;
    cin >> u >> v;
    s = u*u + v*v;
    d = s / 4;
    r = s % 4;
    cout << d << '.';
    if (r == 0) 
        cout << "00";
    else if (r == 1) 
        cout << "25";
    else if (r == 2) 
        cout << "50";
    else 
        cout << "75";
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
ll x[3], y[3];
int main() {
    nothing
    if (fopen("robot.inp", "r")) {
        freopen("robot.inp", "r", stdin);
        freopen("robot.out", "w", stdout);
    }
    cin >> x[1] >> y[1] >> x[2] >> y[2];
    cout << max(abs(x[2] - x[1]), abs(y[2] - y[1]));
    return 0;
}


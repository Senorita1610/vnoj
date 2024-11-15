#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define fi first
#define se second

const int N = 200010;

int n, ans;
typedef pair<int,int> ii;
ii a[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i+n].fi, a[i+n].se = 1;

    sort(a + 1, a + 2 * n + 1);
    for (int i = 2; i <= 2 * n; ++i)
        if (a[i].se != a[i-1].se) ++i, ++ans;
    cout << ans << endl;
}


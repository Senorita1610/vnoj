#include <bits/stdc++.h>
using namespace std;
signed main() {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        set<long long> ans;
        for (long long i = 1; i <= cbrt(n); i++) {
            if (n % i == 0) {
                if (n % (i*(i+1)) == 0) ans.insert(i);
                long long nxt = n/i;
                long long x = sqrt(nxt);
                if (n % (x*(x+1)) == 0) ans.insert(x);
            }
        }
        if (ans.size() == 0) cout << "-1\n";
        else {
            for (auto x: ans) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}


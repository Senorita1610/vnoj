#include <bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
ll test, n, m;

int main() {
    nothing
    cin >> test;
    while (test--) {
    	cin >> n >> m;
    	if (n % (m + 1) != 0) cout << "A" << endl;
    	else cout << "B" << endl;
    }
    return 0;
}


#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    vector<int> y(n);
    for (int i = 0; i<n; i++) {
        cin >> y[i];
    }
    vector<int> q;
    q.push_back(0);
    int ans = -1;
    for (int i = 0; i<n; i++) {
        while(q.back() > y[i]) {
            ans++;
            q.pop_back();
        }
        if(y[i] != q.back()) q.push_back(y[i]);
    }
    cout << ans + q.size() << '\n';
    return 0;
}


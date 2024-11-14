#include <bits/stdc++.h>
 
using namespace std;
 
namespace
{
} // namespace
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
 
    const int X = *max_element(a.begin(), a.end());
 
    vector<long> run(X + 1);
    for (int i = 0; i < n; i++)
    {
        run[a[i] - b[i]]++;
        run[a[i]]--;
    }
    for (int x = 0; x < X; x++)
        run[x + 1] += run[x];
 
    stack<pair<long, int>> st;
    for (int x = 0; x < X; x++)
    {
        long cur = run[x];
        int cnt = 1;
 
        while (!st.empty() && st.top().first <= (cur + st.top().first) / (cnt + 1))
        {
            auto [x, y] = st.top();
            st.pop();
 
            cur += x * y;
            cnt += y;
        }
 
        long q = cur / cnt, d = cur % cnt;
 
        if (d > 0)
            st.emplace(q + 1, d);
        st.emplace(q, cnt - d);
    }
 
    long res = 0;
 
    while (!st.empty())
    {
        auto [x, y] = st.top();
        st.pop();
 
        res += y * x * (x - 1) / 2;
    }
 
    cout << res << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 
    solve();
 
    return 0;
}


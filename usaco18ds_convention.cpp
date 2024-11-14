#include <bits/stdc++.h>
using namespace std;

int n, m, c, l, r = INT_MIN, mid;
vector<int> cows;

bool check(int time)
{
    int mm = 0, now = cows[0], nowi = 0;
    for (int i = 1; i < cows.size(); i++)
    {
        if ((cows[i] - now) > time || (i + 1 - nowi) > c)
            mm++, nowi = i, now = cows[i];
    }
    return mm < m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> c;
    if (n <= m)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cows.push_back(a);
        r = max(r, a);
    }
    sort(cows.begin(), cows.end());
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}


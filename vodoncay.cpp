#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
const int N = 4000010;

int n, a[N], l[N], r[N], f[N];
stack <int> st;
int lt[N], rt[N], nxt[N], arr[N];
ii prv[N];

int cnt;

void _push(int x, int y) {
    arr[++cnt] = y;
    if (!lt[x]) lt[x] = cnt, rt[x] = cnt;
    else nxt[rt[x]] = cnt, rt[x] = cnt;
}

int main() {
    //freopen("vodoncay.inp", "r", stdin);
    //freopen("vodoncay.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        l[i] = i; while(!st.empty() && st.top() > i-a[i]) l[i] = min(l[i], l[st.top()]), st.pop();
        st.push(i);
    }

    st = stack <int> ();
    for (int i = n; i >= 1; --i) {
        r[i] = i; while(!st.empty() && st.top() < i+a[i]) r[i] = max(r[i], r[st.top()]), st.pop();
        st.push(i);
        _push(r[i], i);
    }

    st = stack <int> ();
    for (int i = 1; i <= n; ++i) {
        f[i] = 1e9;
        while(!st.empty() && f[st.top()-1] >= f[i-1]) st.pop();
        st.push(i);
        int last = 0;
        while(!st.empty() && st.top() >= l[i]) f[i] = min(f[i], f[st.top()-1] + 1), last = st.top(), st.pop();
        if (last) st.push(last), prv[i] = ii(-i, last-1);

        if (lt[i]) {
            for (int j = lt[i]; j != 0; j = nxt[j]) if (f[i] > f[arr[j]-1] + 1)
            f[i] = f[arr[j]-1] + 1, prv[i] = ii(arr[j], arr[j]-1);
        }
    }

    int i = n;
    vector <int> ans;
    while(i > 0) {
        ans.push_back(prv[i].first);
        i = prv[i].second;
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) printf("%d ", ans[i]); printf("\n");
}


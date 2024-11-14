#include <cmath>
#include <iostream>
#include <set>
#include <climits>
#include <algorithm>
#include <cassert>
#include <vector>
#include <iomanip>
#include <type_traits>
#include <string>
#include <queue>
#include <map>
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
int lcp (string& s, string& t) {
    map<char,int> myMap1, myMap2;
    for (char c: s) myMap1[c]++;
    for (char c: t) myMap2[c]++;
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) ans += min(myMap1[c], myMap2[c]);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int cnt[n][26];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += vec[i].size();
        for (int j = 0; j < vec[i].size(); j++) {
            cnt[i][vec[i][j] - 'a']++;
        }
    }
    int dp[(1 << n)];
    int mn[(1 << n)][26];
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < 26; j++)
            mn[i][j] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < 26; j++) {
            mn[i][j] = INT_MAX;
            for (int k = 0; k < n; k++) {
                if (!(i & (1 << k))) continue;
                mn[i][j] = min(mn[i ^ (1 << k)][j], cnt[k][j]);
                break;
            }
        }
    }
    int myMin[(1 << n)];
    for (int i = 0; i < (1 << n); i++) {
        myMin[i] = 0;
        for (int j = 0; j < 26; j++) {
            if (mn[i][j] == INT_MAX) continue;
            myMin[i] += mn[i][j];
        }
    }
    for (int i = 0; i < (1 << n); i++) dp[i] = 0;
    for (int i = 0; i < n; i++) dp[(1 << i)] = 0;
    for (int msk = 1; msk < (1 << n); msk++) {
        if (__builtin_popcount(msk) == 1) continue;
        dp[msk] = 0;
        for (int sub_msk = msk; sub_msk; sub_msk = (sub_msk - 1) & msk) {
            dp[msk] = max(dp[msk], dp[sub_msk] + dp[msk ^ sub_msk] + myMin[msk]);
        }
    }
    cout << ans - dp[(1 << n) - 1] + 1;
 
}


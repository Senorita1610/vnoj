#include <bits/stdc++.h>
 
using namespace std;
 
const int nx=1e6+5;
 
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#define ll long long
 
ll n, a[nx], l, r, cnt;
 
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    l=1, r=n;
    while (l<r)
    {
        if (a[l]==a[r]) l++, r--;
        else if (a[l]<a[r]) a[l+1]+=a[l], cnt++, l++;
        else a[r-1]+=a[r], cnt++, r--;
    }
    cout<<cnt;
}


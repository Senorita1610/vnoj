#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 1000005
int n,a[maxn],k;
unordered_map<int,int> D;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i], D[a[i]]++;
    sort(a+1,a+1+n);
    int m=unique(a+1,a+1+n)-a-1;
    n=m;
    int idx=n,ans=0,max_dis=0,min_dis=1e18,kt=k;
    while (idx>=1 && a[idx]>0)
    {
        max_dis=max(max_dis,a[idx]);
        if (D[a[idx]]<=kt) kt-=D[a[idx]], idx--;
        else
        {
            D[a[idx]]-=kt;
            kt=0;
        }
        if (!kt) ans+=max_dis*2, kt=k, max_dis=0;
    }
    ans+=max_dis*2;
    idx=1; kt=k;
    while (idx<=n && a[idx]<0)
    {
        min_dis=min(min_dis,a[idx]);
        if (D[a[idx]]<=kt) kt-=D[a[idx]], idx++;
        else
        {
            D[a[idx]]-=kt;
            kt=0;
        }
        if (!kt) ans+=abs(min_dis)*2, kt=k, min_dis=1e18;
    }
    if (min_dis!=1e18) ans+=abs(min_dis)*2;
    cout<<ans;
}


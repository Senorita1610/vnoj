#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;

ll a[N];
ll cnt1[N],cnt2[N];
ll ma[N];
ll mi[N];
ll n,res,cnt;
ll sum(int i,int j)
{
    return a[j]-a[i-1];
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    ma[n+1]=-MOD;
    mi[n+1]=MOD;
    for (int i=n;i>=1;i--)
    {
        cnt1[i]=cnt1[i+1];
        ma[i]=max(ma[i+1],sum(i,n));
        if (sum(i,n)>ma[i+1]) cnt1[i]=1;
        if (sum(i,n)==ma[i+1]) cnt1[i]++;

        cnt2[i]=cnt2[i+1];
        mi[i]=min(mi[i+1],sum(i,n));
        if (sum(i,n)<mi[i+1]) cnt2[i]=1;
        if (sum(i,n)==mi[i+1]) cnt2[i]++;
    }


    for (int i=1;i<n;i++)
    {
        ll v1=abs(a[i]-ma[i+1]);
        ll v2=abs(a[i]-mi[i+1]);
        if (max(v1,v2)<=res)
        {
            if (v1==res)
                cnt+=cnt1[i+1];
            if (v2==res && mi[i+1]!=ma[i+1])
                cnt+=cnt2[i+1];
            continue;
        }
        cnt=0;
        res=max(v1,v2);
        if (v1==res)
            cnt+=cnt1[i+1];

        if (v2==res && mi[i+1]!=ma[i+1])
            cnt+=cnt2[i+1];
    }
    cout<<res<<" "<<cnt;

}


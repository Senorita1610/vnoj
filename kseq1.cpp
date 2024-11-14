#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int N=301;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
int n,ans;
int f[N][N],a[N];

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int el=1;el<n;el++)
    {
        for (int i=0;i<=el;i++)
            f[i][el]=0;
        for (int i=1;i<=el;i++)
            for (int j=el+1;j<=n;j++)
                f[i][j]=a[i]<a[j] ? f[i-1][j-1]+1:max(f[i][j-1],f[i-1][j]);
        ans=max(ans,f[el][n]);
    }
    cout<<ans;
}


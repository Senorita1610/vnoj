#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105;
int n,vis[maxn],jud;
ll e,a[maxn],sum[maxn][maxn],f[maxn][maxn];
int main(){
    memset(f,0x3f,sizeof(f));
    scanf("%d%lld",&n,&e);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<j;k++){
                sum[i][j]+=abs(a[k]*2-a[i]-a[j]);
            }
        }
    }
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=n;i++){
        f[i][1]=0;
        for(int j=1;j<i;j++){
            f[i][1]+=2*abs(a[i]-a[j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=j-1;k<i;k++){
                f[i][j]=min(f[i][j],f[k][j-1]+sum[k][i]);
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            ll ans=0;
            for(int k=i+1;k<=n;k++){
                ans+=2*abs(a[k]-a[i]);
            }
            f[i][j]+=ans;
        }
    }
    int jl=n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll now=0x3f3f3f3f3f3f3f3f;
        for(int j=i;j<=n;j++){
            now=min(now,f[j][i]);
        }
        if(now<=e){
            ans=now;
            jl=i;
            break;
        }
    }
    printf("%d %lld\n",jl,ans);
    return 0;
}


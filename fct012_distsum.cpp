#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll n,x[N],y[N],ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>x[i]>>y[i];
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    for (ll i=2;i<=n;i++){
        ans+=(i-1)*(x[i]+y[i])-x[i-1]-y[i-1];
        x[i]+=x[i-1];
        y[i]+=y[i-1];
    }
    cout<<ans;
}


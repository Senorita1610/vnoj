#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,a[N],ans[N],x,y;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    x=1,y=n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=n;i>=1;i--){
        if (i%2==n%2){
            ans[x]=a[i];
            x++;
        }
        else{
            ans[y]=a[i];
            y--;
        }
    }
    for (ll i=1;i<=n;i++) cout<<ans[i]<<" ";
}


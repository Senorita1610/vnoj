#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll H=500005;
ll n,h,x,a[H]={},ans=1e+18,ans1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>h;
    for (ll i=1;i<=n;i++){
        cin>>x;
        if (i%2==1){
            a[1]++;
            a[x+1]--;
        }
        else if (i%2==0) a[h-x+1]++;
    }
    a[0]=0;
    for (ll i=1;i<=h;i++) a[i]+=a[i-1];
    for (ll i=1;i<=h;i++)
        if (a[i]<ans){
            ans=a[i];
            ans1=1;
        }
        else if (a[i]==ans) ans1++;
    cout<<ans<<" "<<ans1;
}


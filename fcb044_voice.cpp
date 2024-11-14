#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1005;
ll n,a[N],ans=0;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    for (ll i=1;i<=n;i++){
        ll d=1;
        for (ll j1=i-1;j1>=1;j1--)
            if (a[j1]<=a[j1+1]) d++;
        	else break;
        for (ll j1=i+1;j1<=n;j1++)
            if (a[j1]<=a[j1-1]) d++;
        	else break;
        ans=max(ans,d);
    }
    cout<<ans;
}


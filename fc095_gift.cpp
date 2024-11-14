#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000000;
ll n,d,ans=0,a[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]>a[i-1] && i>1) d++;
        else d=1;
        ans=max(ans,d);
    }
    cout<<max(ans,d);
}


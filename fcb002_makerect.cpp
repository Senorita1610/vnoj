#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,s=1,k=0,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,greater<ll>());
    for (ll i=1;i<n;i++){
        if (a[i]==a[i+1]){
            s*=a[i];
            i++;
            k++;
        }
        if (k==2) break;
    }
    (k==2) ? cout<<s : cout<<0;
}


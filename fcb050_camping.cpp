#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=500005,inf=1e+18;
ll n,x,d=0,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>x;
    for (ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=inf,a[n+1]=inf;
    for (ll i=1;i<=n;i++){
        d+=a[i]!=a[i-1];
        if (x==a[i]){
            cout<<d;
            return 0;
        }
        else if (x>a[i] && x<a[i+1]){
            cout<<d+1;
            return 0;
        }
    }
}


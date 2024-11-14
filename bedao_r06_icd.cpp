#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000006;
ll n,x=0,a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=x;
        if (i!=n){
            x+=a[i]/(n-i);
            a[i]%=(n-i);
        }
    }
    for (ll i=1;i<=n;i++) cout<<a[i]<<" ";
}


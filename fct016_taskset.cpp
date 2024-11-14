#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll inf=1e+18;
ll n,x=1,ans=inf;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while (x<=n){
        ans=min(ans,n-x);
        if (x*3<=n) ans=min(ans,n-x*3);
        x*=2;
    }
    cout<<ans;
}


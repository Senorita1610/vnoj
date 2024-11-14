#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,s,ans=0,o=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    for (ll i=0;i<=min(n,s);i++)
        if (s-i<=2*n)
            ans+=(min(s-i,n)-max(o,s-i-n)+1);
    cout<<ans;
}


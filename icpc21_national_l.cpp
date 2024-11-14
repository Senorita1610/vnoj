#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll A=10000000;
ll n,a,ans=0,x[A+5]={},mp[A+5]={};
void Build(){
    for (ll i=2;i<=sqrt(A);i++)
        for (ll j=1;j<=A/i/i;j++)
            x[j*i*i]=i;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Build();
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        while (x[a]!=0) a/=x[a];
        ans+=mp[a];
        mp[a]++;
    }
    cout<<ans;
}


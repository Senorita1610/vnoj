#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll A=1000000;
ll a,b,ans=0,x[A+5],mp[A+5]={};
void Build(){
    for (ll i=1;i<=A;i++) x[i]=1;
    for (ll i=2;i<=A;i++)
        if (x[i]==1)
            for (ll j=1;j<=A/i;j++)
                x[i*j]*=i;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Build();
    cin>>a>>b;
    for (ll i=a;i<=b;i++){
        ans+=mp[x[i]];
        mp[x[i]]++;
    }
    cout<<ans;
}


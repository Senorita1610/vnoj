#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100005;
ll a,b,x[N],ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b;
    for (ll i=1;i<=N-5;i++)
        for (ll j=i*2;j<=N-5;j+=i)
            x[j]+=i;
    for (ll i=a;i<=b;i++)
        if (x[i]>i) ans++;
    cout<<ans;
}


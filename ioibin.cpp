#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=10005;
ll n,p,a[N],t,x,y;
ll Find(ll i){
    if (i==a[i]) return i;
    return a[i]=Find(a[i]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>p;
    for (ll i=1;i<=N-5;i++) a[i]=i;
    while (p--){
        cin>>x>>y>>t;
        x=Find(x);
        y=Find(y);
        if (t==1) a[y]=x;
        else if (t==2) cout<<(x==y)<<endl;
    }
}


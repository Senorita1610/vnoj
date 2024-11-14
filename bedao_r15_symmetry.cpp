#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll l,r,a[10],ans=0;
void Check(ll i){
    ll s=0;
    for (ll j=1;j<=i;j++)
        s=s*10+a[j];
    ans+=s*(s>=l && s<=r);
}
void Try(ll i, ll x){
    if (x==1){
        for (ll j=1;j<=9;j++){
            a[x]=j;
            a[i-x+1]=j;
            if (x<(i+1)/2) Try(i,x+1);
            else Check(i);
        }
    }
    else{
        for (ll j=0;j<=9;j++){
            a[x]=j;
            a[i-x+1]=j;
            if (x<(i+1)/2) Try(i,x+1);
            else Check(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l>>r;
    for (ll i=1;i<=9;i++) Try(i,1);
    cout<<ans;
}


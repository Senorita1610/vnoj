#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll A=1000005;
ll t,n,a,o[A]={};
void Build(){
    for (ll i=2;i<=A;i++)
        if (o[i]==0)
            for (ll j=1;j<=A/i;j++)
                o[i*j]=i;
}
void Solve(){
    cin>>n;
    ll x[A]={};
    for (ll i=1;i<=n;i++){
        cin>>a;
        while (a>1){
            x[o[a]]++;
            a/=o[a];
        }
    }
    for (ll i=1;i<=n;i++){
        cin>>a;
        while (a>1){
            x[o[a]]--;
            a/=o[a];
        }
    }
    for (ll i=1;i<=A-5;i++)
        if (x[i]<0 && i!=2 && i!=5){
            cout<<"repeating"<<endl;
            return;
        }
    cout<<"finite"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Build();
    cin>>t;
    while (t--) Solve();
}


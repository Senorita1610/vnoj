#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x[35],d=30;
void Build(){
    x[0]=1;
    for (ll i=1;i<=30;i++) x[i]=x[i-1]*2;
}
vector <ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    Build();
    while (n>0){
        while (n<x[d]) d--;
        v.push_back(x[d]);
        n-=x[d];
    }
    for (ll i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";
}


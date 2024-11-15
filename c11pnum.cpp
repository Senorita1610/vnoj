#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

const ll A=2642249;
ll t,n,k,a[A]={},x[A],d=0;
vector <ll> v[15];
void SangNt(){
    a[1]=1;
    ll i=1;
    while (i*i<=A){
        while (a[i]==1) i++;
        for (ll j=2;j<=A/i;j++)
            a[i*j]=1;
        i++;
    }
    for (ll i=1;i<=A-5;i++)
        if (a[i]==0){
            d++;
            x[d]=i;
        }
}
void Build(){
    for (ll i=3;i<=10;i++){
        ll s=1;
        for (ll j=1;j<=i;j++) s*=x[j];
        v[i].push_back(s);
        for (ll j=i+1;j<=d;j++){
            s/=x[j-i];
            s*=x[j];
            v[i].push_back(s);
        }
    }
}
void Solve(){
    cin>>n>>k;
    if (v[k][0]>n){
        cout<<-1<<endl;
        return;
    }
    for (ll i=0;i<v[k].size();i++)
        if (n<v[k][i+1] || i==v[k].size()-1 || v[k][i]>v[k][i+1]){
            cout<<v[k][i]<<endl;
            return;
        }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SangNt();
    Build();
    cin>>t;
    while(t--) Solve();
}


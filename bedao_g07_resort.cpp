#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=200005;
ll n,a,x1=0,x2=0,s[N],ans=0,o=0;
void SangNt(){
    for (ll i=1;i<=N;i++) s[i]=1;
    s[1]=0;
    ll i=1;
    while (i<=sqrt(N)){
        while (s[i]==0) i++;
        for (ll j=2;j<=N/i;j++)
            s[i*j]=0;
        i++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    SangNt();
    for (ll i=1;i<=n;i++){
        cin>>a;
        (a==1) ? x1++ : x2++;
    }
    if (x2==0){
        for (ll i=1;i<=x1;i++){
            o++;
            ans+=s[o];
        }
        cout<<ans;
        return 0;
    }
    else if (x1==0){
        cout<<1;
        return 0;
    }
    else{
        ans=2,o=3;
        for (ll i=1;i<x2;i++){
            o+=2;
            ans+=s[o];
        }
        for (ll i=1;i<x1;i++){
            o++;
            ans+=s[o];
        }
        cout<<ans;
    }
}


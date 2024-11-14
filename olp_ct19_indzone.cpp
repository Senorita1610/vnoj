#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD=998244353;
ll n,ans,x[2][2]={1,1,1,0};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if (n==0){
        cout<<1;
        return 0;
    }
    while (n>0){
        ll d=1,s[2][2]={1,1,1,0};
        while (d*2<=n){
            d*=2;
            ll u[2][2];
            u[0][0]=(s[0][0]*s[0][0]+s[0][1]*s[1][0])%MOD;
            u[0][1]=(s[0][0]*s[0][1]+s[0][1]*s[1][1])%MOD;
            u[1][0]=(s[1][0]*s[0][0]+s[1][1]*s[1][0])%MOD;
            u[1][1]=(s[1][0]*s[0][1]+s[1][1]*s[1][1])%MOD;
            s[0][0]=u[0][0];
            s[0][1]=u[0][1];
            s[1][0]=u[1][0];
            s[1][1]=u[1][1];
        }
        n-=d;
        ll u[2][2];
        u[0][0]=(s[0][0]*x[0][0]+s[0][1]*x[1][0])%MOD;
        u[0][1]=(s[0][0]*x[0][1]+s[0][1]*x[1][1])%MOD;
        u[1][0]=(s[1][0]*x[0][0]+s[1][1]*x[1][0])%MOD;
        u[1][1]=(s[1][0]*x[0][1]+s[1][1]*x[1][1])%MOD;
        x[0][0]=u[0][0];
        x[0][1]=u[0][1];
        x[1][0]=u[1][0];
        x[1][1]=u[1][1];
    }
    cout<<(x[0][0]*x[0][1])%MOD;
}


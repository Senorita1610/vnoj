#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD=1e9+7;
ll n,x[2][2]={1,1,1,0};;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if (n<=1){
        cout<<n;
        return 0;
    }
    n-=2;
    while (n>0){
        ll d=1,s[2][2]={1,1,1,0};
        while (d*2<=n){
            d*=2;
            ll u[2][2]={s[0][0],s[0][1],s[1][0],s[1][1]};
            s[0][0]=(u[0][0]*u[0][0]+u[0][1]*u[1][0])%MOD;
            s[0][1]=(u[0][0]*u[0][1]+u[0][1]*u[1][1])%MOD;
            s[1][0]=(u[1][0]*u[0][0]+u[1][1]*u[1][0])%MOD;
            s[1][1]=(u[1][0]*u[0][1]+u[1][1]*u[1][1])%MOD;
        }
        n-=d;
        ll u[2][2]={x[0][0],x[0][1],x[1][0],x[1][1]};
        x[0][0]=(u[0][0]*s[0][0]+u[0][1]*s[1][0])%MOD;
        x[0][1]=(u[0][0]*s[0][1]+u[0][1]*s[1][1])%MOD;
        x[1][0]=(u[1][0]*s[0][0]+u[1][1]*s[1][0])%MOD;
        x[1][1]=(u[1][0]*s[0][1]+u[1][1]*s[1][1])%MOD;
    }
    cout<<x[0][0];
}


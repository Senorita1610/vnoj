#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a,b,x,y,r,m=1e+18;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a>>b;
    while (n--){
        cin>>x>>y>>r;
        ll d=sqrt((x-a)*(x-a)+(b-y)*(b-y));
        if (d*d==(x-a)*(x-a)+(b-y)*(b-y)) d--;
        d-=r;
        m=min(m,d);
    }
    cout<<m;
}


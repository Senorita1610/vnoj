#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m,x=0,y=0;
char a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++){
            cin>>a;
            x+=(a=='1' && (i+j)%2==1)+(a=='0' && (i+j)%2==0);
            y+=(a=='1' && (i+j)%2==0)+(a=='0' && (i+j)%2==1);
        }
    cout<<min(x,y);
}


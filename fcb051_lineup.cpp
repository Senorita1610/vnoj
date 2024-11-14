#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a,b,ans=0,x=0,y=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a>>b;
        x+=a;
        y+=b;
        ans+=(a%2!=b%2);
    }
    if ((x+y)%2==1 || (x%2==1 && y%2==1 && ans==0)) cout<<-1;
    else if (x%2==0 && y%2==0) cout<<0;
    else cout<<1;
}


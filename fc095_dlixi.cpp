#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c,x=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c;
    (c==0) ? cout<<0 : cout<<max(x,b/c-(a-1)/c+(a==0));
}


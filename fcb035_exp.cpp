#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,a,b,c,x,y,z;
void Solve(){
    cin>>a>>b>>c;
    x=min(abs(a+b+c),min(abs(a+b-c),abs(a+b*c)));
    y=min(abs(a-b+c),min(abs(a-b-c),abs(a-b*c)));
    z=min(abs(a*b+c),min(abs(a*b-c),abs(a*b*c)));
    cout<<min(x,min(y,z))<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}


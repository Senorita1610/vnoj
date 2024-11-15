#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,x,y,a,ans;
void Solve(){
    ans=0;
    cin>>x>>y>>a;
    (a%(x+y)==0) ? ans+=a/(x+y)*x : ans+=min((a/(x+y)+1)*x,(a/(x+y)*x+a%(x+y)));
    cout<<ans*5<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}


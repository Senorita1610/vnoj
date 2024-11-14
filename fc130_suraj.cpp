#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,m,k,x,y,ans;
void Solve(){
    cin>>m>>k;
    y=m/k;
    x=sqrt(y*2);
    x-=(x*(x+1)>y);
    m-=x*(x+1)*k/2;
    ans=x*k;
    while (m>=(x+1)*k){
        m-=(x+1)*k;
        ans+=k;
        x++;
    }
    cout<<ans+m/(x+1)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}


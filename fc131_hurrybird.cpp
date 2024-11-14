#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,n,m,x,y;
void Solve(){
    cin>>n>>m>>x>>y;
    if (n==1){
        cout<<(m-1)*x<<endl;
        return;
    }
    else if (m==3){
        cout<<(n-1)*x<<endl;
        return;
    }
    ll ans1=(n+m-2)*x,ans2=(max(n,m)-1)*y,ans3=(min(n,m)-1)*y+(max(n,m)-min(n,m))*x;
    if ((n+m)%2==1) ans2+=(x-y);
    cout<<min(ans1,min(ans2,ans3))<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}


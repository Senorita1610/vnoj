#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,x[50];
void Solve(){
    b=x[a]-b;
    ll ans=0;
    for (ll i=31;i>=1;i--)
        if (b>=x[i]){
            if (b==x[i]) goto End;
            b=2*x[i]-b;
            ans++;
        }
    End:
    (ans%2==0) ? cout<<"D"<<endl : cout<<"U"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    x[1]=2;
    for (ll i=2;i<=31;i++) x[i]=x[i-1]*2;
    while (cin>>a>>b){
        if (a==0 && b==0) break;
        else Solve();
    }
}


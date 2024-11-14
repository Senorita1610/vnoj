#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll t,m,n;
void Solve(){
    cin>>m>>n;
    if (m==1){
        cout<<1<<endl;
    }
    else if (m>=2){
        ll s=n/3*2;
        n%=3;
        cout<<s+(n>=1)<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--) Solve();
}


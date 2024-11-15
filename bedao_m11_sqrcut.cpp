#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a,b,ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a>>b;
        ans=0;
        while (a!=b){
            (a>b) ? a-=b : b-=a;
            ans++;
        }
        cout<<ans<<endl;
    }
}


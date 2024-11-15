#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a,ans=0;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        ans+=a;
    }
    (ans%2==0) ? cout<<"YES" : cout<<"NO";
}


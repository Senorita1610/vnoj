#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,ans=0;
ll Change(ll n){
    ll s=0;
    while (n>0){
        s=s*10+n%10;
        n/=10;
    }
    return s;
}
ll Check(ll n){
    return (__gcd(n,Change(n))==1) ? 1 : 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b;
	for (ll i=a;i<=b;i++)
        if (Check(i)==1) ans++;
    cout<<ans;
}


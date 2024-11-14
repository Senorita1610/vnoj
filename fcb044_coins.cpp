#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,a,b;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>a>>b;
    for (ll i=1;i<=n;i++)
        (a<=b) ? a+=k : b+=k;
    cout<<abs(a-b);
}


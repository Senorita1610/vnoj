#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string a;
ll n,ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>n;
    for (ll i=0;i<a.size();i++)
    	ans+=(int(a[i])-97+n)%26;
    cout<<ans;
}


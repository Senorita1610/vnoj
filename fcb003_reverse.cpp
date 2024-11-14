#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll S=200005;
string s;
ll n,x,a[S]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>n;
    for (ll i=1;i<=n;i++){
        cin>>x;
        a[x-1]++;
    }
    for (ll i=0;i<s.size()/2;i++) a[i]+=a[s.size()-i-1];
    for (ll i=0;i<s.size()/2;i++){
        if (i!=0) a[i]+=a[i-1];
        if (a[i]%2==1) swap(s[i],s[s.size()-i-1]);
    }
    cout<<s;
}


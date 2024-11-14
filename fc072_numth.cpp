#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MaxN=100001;
ll n=1,k,a[MaxN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    while (cin>>a[n]) n++;
    sort(a+1,a+n,greater<ll>());
    cout<<a[k];
}


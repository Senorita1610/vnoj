#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,k,x,ans=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    ans=(n/k)*(n/k)*(n/k);
    if (k%2==0){
        (n%k>=k/2) ? x=n/k+1 : x=n/k;
        ans+=x*x*x;
    }
    cout<<ans;
}


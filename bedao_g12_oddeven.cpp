#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=1000000;
ll n,a,x=0,y=0,ans=0;
vector <ll> v1,v2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (ll i=1;i<=n;i++){
        cin>>a;
        x+=(a%2==1);
        y+=(a%2==0);
        if (a%2!=i%2)
            (i%2==1) ? v1.push_back(i) : v2.push_back(i);
    }
    if (x!=(n+1)/2 || y!=n/2) cout<<-1;
    else{
        for (ll i=0;i<v1.size();i++) ans+=abs(v1[i]-v2[i]);
        cout<<ans;
    }
}


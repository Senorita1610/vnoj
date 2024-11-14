#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,m,k,x,y,a=0,b=0;
unordered_map <ll,ll> mp1,mp2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    while (k--){
        cin>>x>>y;
        a+=(mp1[x]==0);
        b+=(mp2[y]==0);
        mp1[x]=1;
        mp2[y]=1;
    }
    cout<<a*b;
}


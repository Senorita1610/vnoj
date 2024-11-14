#ifndef Local
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define lim 1000001
using namespace std;
const int mod=1000000007ll;
 
void solve(){
    int n;
    cin>>n;
    int a[lim];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        int tem;
        cin>>tem;
        a[tem]++;
    }
    int cur=0;
    for(int i=1e6;0<=i;i--){
        cur+=a[i];
        if(i<=cur){
            cout<<i;
            return;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
#ifdef Local  
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
}


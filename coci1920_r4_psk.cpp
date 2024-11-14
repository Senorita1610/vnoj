#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ld long double
#define ll long long
#define pii pair<int,int>
#define pll pair<ll, ll>
const int MAXN = 1e3+7;
pll v[MAXN];
ll ans[MAXN];
ll total = 0;
int main(){
    fastio;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        ll ti,zi;
        cin>>ti>>zi;
        total += ti;
        v[i] = {zi, i};
    }
    sort(v, v+n);
    int cnt = 0;
    for(int i=n-1; i>=0; i--){
        ans[v[i].second] = min(v[i].first, total);
        total = max(0LL, total - v[i].first);
        if(ans[v[i].second]==0)cnt++;
    }
    cout<<cnt<<endl;
    for(int i=0; i<n; i++){
        if(i>0)cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,q,preSum[N];
pair<int,int>a[N];
bool cmp(pair<int,int>u,pair<int,int>v){
    return u.second<v.second;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) preSum[i]=preSum[i-1]+a[i].first;
    while(q--){
        int x,idx=0;
        cin>>x;
        int l=1,r=n;
        while(r-l>=0){
            int m=l+r>>1;
            if (a[m].second<=x){
                idx=m;
                l=m+1;
            }
            else r=m-1;
        }
        cout << preSum[idx] << "\n";
    }
}


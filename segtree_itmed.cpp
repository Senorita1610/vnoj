#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll N=100000;
ll n,k,ans=0,a[N+5];
deque <ll> dq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (ll i=1;i<=n;i++){
        cin>>a[i];
        if (i!=1){
            while (dq.front()<i-k) dq.pop_front();
            if (a[dq.front()]>0) a[i]+=a[dq.front()];
        }
        while (!dq.empty() && a[i]>=a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        ans=max(ans,a[i]);
    }
    cout<<ans;
}


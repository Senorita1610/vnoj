#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[3*N+5],dpl[3*N+5],dpr[3*N+5],res=LLONG_MIN;
priority_queue<long long>q1;
priority_queue<long long, vector<long long>,greater<long long>>q2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=3*n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        dpl[i]=dpl[i-1]+a[i];
        q2.push(a[i]);
    }
    for (int i=n+1;i<=2*n;i++) {
        long long temp=q2.top();
        if (temp<a[i]) {
            q2.pop();
            q2.push(a[i]);
            dpl[i]=dpl[i-1]+a[i]-temp;
        } else dpl[i]=dpl[i-1];
    }
    for (int i=3*n;i>=2*n+1;i--) {
        dpr[i]=dpr[i+1]+a[i];
        q1.push(a[i]);
    }
    for (int i=2*n;i>=n+1;i--) {
        long long temp=q1.top();
        if (temp>a[i]) {
            q1.pop();
            q1.push(a[i]);
            dpr[i]=dpr[i+1]+a[i]-temp;
        } else dpr[i]=dpr[i+1];
    }
    for (int i=n;i<=2*n;i++) res=max(res,dpl[i]-dpr[i+1]);
    cout<<res;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
int h[2*N+5];
int bit[2*N+5];
long long res;
void update(int u) {
	int idx=u;
	while (idx<=2*N) {
		bit[idx]++;
		idx+=(idx&(-idx));
	}
}
int get(int u) {
	int idx=u,ans=0;
	while (idx>0) {
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>h[i];
    	if (h[i]>=k) h[i]=1;
    	else h[i]=-1;
    }
    update(N);
    int sum=0;
    for (int i=1;i<=n;i++) {
    	sum+=h[i];
    	res+=get(sum+N);
    	update(sum+N);
    }
    cout<<res;
}


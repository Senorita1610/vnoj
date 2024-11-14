#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k,r,p;
long long res,sum[505][505];
vector<pair<int,int>>vc[N+5];
long long calc(int t,int mask) {
	bool f=false;
	int x,y,u,v;
	for (int i=0;i<p;i++) {
		if (mask>>i&1) {
			if (!f) {
				f=true;
				u=vc[t][i].first,v=vc[t][i].second;
				x=u+r-1,y=v+r-1;
			} else {
				if (u>vc[t][i].first+r-1||x<vc[t][i].first) return 0;
				u=max(u,vc[t][i].first);
				x=min(x,vc[t][i].first+r-1);
				if (v>vc[t][i].second+r-1||y<vc[t][i].second) return 0;
				v=max(v,vc[t][i].second);
				y=min(y,vc[t][i].second+r-1);
			}
		} 
	}
	return sum[x][y]-sum[u-1][y]-sum[x][v-1]+sum[u-1][v-1];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k>>r>>p;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		long long t;
    		cin>>t;
    		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t;
    	}
    }
    for (int i=1;i<=k;i++) {
    	for (int j=1;j<=p;j++) {
    		pair<int,int>p;
    		cin>>p.first>>p.second;
    		vc[i].push_back(p);
    	}
    }
    for (int i=1;i<=k;i++) {
    	long long cur=0;
    	for (int mask=1;mask<(1<<p);mask++) {
    		if (__builtin_popcount(mask)%2==1) cur+=calc(i,mask);
    		else cur-=calc(i,mask);
    	}
    	res=max(res,cur);
    }
    cout<<res;
}


#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,res,m;
pair<long long,long long>p[N+5];
long long sum[N+5];
bool comp(pair<long long,long long>a,pair<long long,long long>b) {
	return a.first>b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+m,comp);
    for (int i=1;i<=m;i++) sum[i]=sum[i-1]+p[i].first;
    res=sum[min(m,n)];
    for (int i=1;i<=m;i++) {
    	long long lo=1,hi=m,ans=0;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (p[mid].first>=p[i].second) {
    			ans=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	if (ans<i) {
    		ans=min(ans,n-1);
    		res=max(res,sum[ans]+p[i].first+(n-ans-1)*p[i].second);
    	} else if (ans<=n) res=max(res,sum[ans]+(n-ans)*p[i].second);
    }
    cout<<res;
}


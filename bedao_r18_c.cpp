#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
pair<long long,long long>p[N+5];
long long res;
priority_queue<long long,vector<long long>,greater<long long>>pq;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].second;
    	res+=p[i].second;
    }
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
    	pq.push(p[i].second);
    	while (pq.size()>p[i].first){
    		res-=pq.top();
    		pq.pop();
    	}
    }
    cout<<res;
}


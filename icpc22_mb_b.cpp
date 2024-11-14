#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long m,n,s;
int d[N+5];
pair<long long,long long>p[11];
queue<long long>q;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>m>>n>>s;
	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	q.push(s);
	memset(d,-1,sizeof(d));
	d[s]=0;
	while (!q.empty()) {
		long long t=q.front();
		q.pop();
		for (int i=1;i<=n;i++) {
			long long x=(t*p[i].first+p[i].second)%m;
			if (d[x]==-1) {
				d[x]=d[t]+1;
				q.push(x);
			}
		}
	}
	cout<<d[0];
}


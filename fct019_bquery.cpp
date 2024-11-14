#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,m,q;
long long row[N+5],col[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>q;
	while (q--) {
		int type;
		cin>>type;
		if (type==1) {
			long long r,x;
			cin>>r>>x;
			row[r]+=x;
		} else if (type==2) {
			long long c,x;
			cin>>c>>x;
			col[c]+=x;
		} else {
			int x,y,u,v;
			cin>>x>>y>>u>>v;
			long long m1=0,m2=0;
			for (int i=x;i<=u;i++) m1=max(m1,row[i]);
			for (int i=y;i<=v;i++) m2=max(m2,col[i]);
			cout<<m1+m2<<'\n';
		}
	}
}


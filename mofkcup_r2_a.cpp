#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,q,sum[N+5][N+5];
char a[N+5][N+5];
struct dat{
	int a,b,c,d;
	bool operator < (const dat &other) const {
		if (a!=other.a) return a<other.a;
		if (b!=other.b) return b<other.b;
		if (c!=other.c) return c<other.c;
		return d<other.d;
	}
};
set<dat>s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		cin>>a[i][j];
    		sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(a[i][j]=='B');
    	}
    }
    for (int i=1;i<n;i++) {
    	for (int j=1;j<m;j++) {
    		int a=sum[i][j],b=sum[i][m]-sum[i][j],c=sum[n][j]-sum[i][j],d=sum[n][m]-a-b-c;
    		s.insert({a,b,c,d});
    	}
    }
    while (q--) {
    	int a,b,c,d;
    	cin>>a>>b>>c>>d;
    	if (s.count({a,b,c,d})!=0) cout<<"YES"<<'\n';
    	else cout<<"NO"<<'\n';
    }
}


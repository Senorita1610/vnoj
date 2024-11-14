#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e2+10;
int k,r,m,n,res;
int x[N],y[N],u[N],v[N],p[N],d[N];
int close1[N][N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>k>>r>>m;
	forin(i,1,m) cin>>x[i]>>y[i];
	cin>>n;
	forin(i,1,n) cin>>u[i]>>v[i]>>p[i];
	forin(i,1,m) forin(j,1,n){
		int dist=(u[j]-x[i])*(u[j]-x[i])+(v[j]-y[i])*(v[j]-y[i]);
		if(dist<=r*r) close1[i][j]=1;
	}
	forin(mask,0,(1<<m)-1) if(__builtin_popcount(mask)==k){
		int ans=0;
		forin(i,1,n) d[i]=0;
		forin(i,1,m) if((mask>>(i-1))&1){
			forin(j,1,n) if(close1[i][j]&&!d[j]){
				ans+=p[j];
				d[j]=1;
			}
		}
		res=max(res,ans);
	}
	cout<<res;
}


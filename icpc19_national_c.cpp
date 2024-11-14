#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int,int>;
using PLL = pair<LL,LL>;
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define RFOR(i,b,a) for(int i=b-1;i>=a;i--)
#define FILL(a,b) memset(a,b,sizeof(a))
void dout(){
	cerr<<endl;
}
template <typename Head, typename... Tail>
void dout(Head H, Tail... T){
	cerr<<H<<" ";
	dout(T...);
}
bool intersect(int x1,int y1,int z1,int u1,int v1,int w1,int x2, int y2,int z2,int u2,int v2,int w2){
	return max(x1,x2)<=min(u1,u2)&&max(y1,y2)<=min(v1,v2)&&max(z1,z2)<=min(w1,w2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(true){
		int a,b,c,m;
		cin>>a;
		if(a==-1) break;
		cin>>b>>c>>m;
		vector<int>cx(m),cy(m),cz(m),x(m),y(m),z(m),u(m),v(m),w(m);
		FOR(i,0,m) cin>>cx[i]>>cy[i]>>cz[i];
		LL vol=0;
		bool ok=true;
		FOR(i,0,m){
			cin>>x[i]>>y[i]>>z[i]>>u[i]>>v[i]>>w[i];
			if(x[i]>u[i]) ok=false;
			if(y[i]>v[i]) ok=false;
			if(z[i]>w[i]) ok=false;
			ok&=u[i]<=a&&v[i]<=b&&w[i]<=c;
			vol+=(LL)(u[i]-x[i]+1LL)*(v[i]-y[i]+1LL)*(w[i]-z[i]+1LL);
		}
		ok&=vol==(LL)a*b*c;
		FOR(i,0,m){
			FOR(j,0,i){
				ok&=!intersect(x[i],y[i],z[i],u[i],v[i],w[i],x[j],y[j],z[j],u[j],v[j],w[j]);
			}
			bool ch=0;
			FOR(j,i,i+1)
				ch|=intersect(x[i],y[i],z[i],u[i],v[i],w[i],cx[j],cy[j],cz[j],cx[j],cy[j],cz[j]);
			ok&=ch;
		}
		cout<<(ok?"YES\n":"NO\n");
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define ALL(a) a.begin(),a.end()
#define FastIO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define IN freopen("input.txt","r+",stdin)
#define OUT freopen("output.txt","w+",stdout)
#define TEST
#ifdef TEST
#define DBG(a) cout<<#a<<" --> "<<a<<endl;
#define NL cout<<"\n";
#else
#define DBG(A);
#define NL cout<<"\n";
#endif

template<class T1,class T2>
ostream &operator <<(ostream &os,const pair<T1,T2>&p){
	os<<"{"<<p.first<<","<<p.second<<"}";
	return os;
}
const int N=3e5+5;
const int oo=1e9+7;
pii x[N];
pii y[N];
pii z[N];
struct point{
	int x,y,z,id;
	bool operator <(const point &p){
		if(x!=p.x) return x<p.x;
		if(y!=p.y) return y<p.y;
		if(z!=p.z) return z<p.z;
	}
};
int a,b,c,m;
point v[N];
void solve_y(int i,int j,int lo,int hi);
void solve_z(int i,int j,int lo,int hi);
void solve_x(int i,int j,int lo,int hi){
	if(i==j){
		x[v[i].id].first=lo;
		x[v[i].id].second=hi;
		y[v[i].id].first=1;
		y[v[i].id].second=b;
		z[v[i].id].first=1;
		z[v[i].id].second=c;
		return;
	}
	while(i<=j){
		int k=i;
		while(k<=j and v[k].x==v[i].x) k++;
		k--;
		int up;
		if(k==j) up=hi;
		else up=v[i].x;
		for(int ii=i;ii<=k;ii++) x[v[ii].id]={lo,up};
		lo=up+1;
		solve_y(i,k,1,b);
		i=k+1;
	}
}
void solve_y(int i,int j,int lo,int hi){
	if(i==j){
		y[v[i].id].first=lo;
		y[v[i].id].second=hi;
		z[v[i].id].first=1;
		z[v[i].id].second=c;
		return;
	}
	while(i<=j){
		int k=i;
		while(k<=j and v[k].y==v[i].y) k++;
		k--;
		int up;
		if(k==j) up=hi;
		else up=v[i].y;
		for(int ii=i;ii<=k;ii++) y[v[ii].id]={lo,up};
		solve_z(i,k,1,c);
		lo=up+1;
		i=k+1;
	}
}
void solve_z(int i,int j,int lo,int hi){
	if(i==j){
		z[v[i].id].first=lo;
		z[v[i].id].second=hi;
		return;
	}
	while(i<=j){
		int k=i;
		while(k<=j and v[k].z==v[i].z) k++;
		k--;
		int up;
		if(k==j) up=hi;
		else up=v[i].z;
		for(int ii=i;ii<=k;ii++) z[v[ii].id]={lo,up};
		assert(i==k);
		lo=up+1;
		i=k+1;
	}
}
int32_t main(){
	FastIO;
	while(1){
		cin>>a;
		if(a==-1) break;
		cin>>b>>c>>m;
		for(int i=0;i<m;i++){
			cin>>v[i].x>>v[i].y>>v[i].z;
			v[i].id=i;
		}
		sort(v,v+m);
		solve_x(0,m-1,1,a);
		cout<<"YES\n";
		for(int i=0;i<m;i++) cout<<x[i].first<<" "<<y[i].first<<" "<<z[i].first<<" "<<x[i].second<<" "<<y[i].second<<" "<<z[i].second<<"\n";
	}
}


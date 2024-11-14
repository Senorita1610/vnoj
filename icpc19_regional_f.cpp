#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
double Inf=1e12;
double Ans[N];
int a[N],b[N],d[N],n,m;
vector<pair<double,int>>q;
void solve(){
	double S=m;
	for(int i=1;i<=N;i++){
		Ans[i]=a[i];
		S-=a[i];
	}
	set<int>f;
	double W=0,M=0;
	for(int i=0;i<2*N;i++){
		double now=q[i].first,nx=q[i+1].first;
		int idx=abs(q[i].second);
		if(q[i].second<0){
			f.insert(idx);
			W+=d[idx];
			M+=a[idx];
		}else{
			f.erase(idx);
			Ans[idx]=b[idx];
			S-=(b[idx]-a[idx]);
			W-=d[idx];
			M-=a[idx];
		}
		if(nx>=Inf||(S+M)<=nx*W){
			double tot=S+M;
			for(auto& id:f){
				Ans[id]=tot*d[id]/W;
			}
			return;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&d[i]);
		q.push_back(make_pair(1.0*a[i]/d[i],-i));
		q.push_back(make_pair(1.0*b[i]/d[i],i));
	}
	q.push_back(make_pair(Inf,0));
	sort(q.begin(),q.end());
	solve();
	for(int i=1;i<=n;i++){
		printf("%.8f\n",Ans[i]);
	}
	return 0;
}


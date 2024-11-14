#include<bits/stdc++.h>
using namespace std;
int n,h,r,s;
const int maxn=3e5+10;
int up[maxn],hor[maxn];
struct rope{
	int h,len,to;
	bool operator<(const rope& rhs) const{
		return h<rhs.h;
	}
};
vector<rope>P[maxn];
int main(){
	scanf("%d%d%d%d",&n,&h,&r,&s);
	for(int i=0;i<r;i++){
		int len,a,b,H;
		scanf("%d%d%d%d",&len,&a,&b,&H);
		P[a].push_back(rope{H,len,b});
		P[b].push_back(rope{H,len,a});
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",up+i,hor+i);
		sort(P[i].begin(),P[i].end());
	}
	int ans=0;
	for(int i=1;i<=s;i++){
		int pos,nowh,x,y;
		scanf("%d%d%d%d",&pos,&nowh,&x,&y);
		long long up_dis=0;
		long long hor_dis=0;
		while(1){
			if(P[pos].empty()){
				up_dis+=nowh;
				break;
			}
			auto p =lower_bound(P[pos].begin(),P[pos].end(),rope{nowh,0,0});
			if(p==P[pos].begin()){
				up_dis+=nowh;
				break;
			}
			rope x=*prev(p);
			up_dis+=nowh-x.h;
			hor_dis+=x.len;
			pos=x.to;
			nowh=x.h;
		}
		long long sum=up_dis*up[pos]+hor_dis*hor[pos];
		if(sum%(x+y)>=1&&sum%(x+y)<=x) ans++;
	}
	printf("%d\n",ans);
}


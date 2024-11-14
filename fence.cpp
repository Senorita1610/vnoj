#include<bits/stdc++.h>
using namespace std;
const int N=255;
int n,cnt,ans;
int f[N];
struct P{
	int u,v,x,y;
}a[N],e[N*N];
inline bool cmp(P i,P j){
	return atan2(i.y,i.x)<atan2(j.y,j.x);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			e[++cnt].u=i,e[cnt].v=j;
			e[cnt].x=a[j].x-a[i].x,e[cnt].y=a[j].y-a[i].y;
		}
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[j]=-1e9+7;
		f[i]=0;
		for(int j=1;j<=cnt;j++)
			f[e[j].v]=max(f[e[j].v],f[e[j].u]+1);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}


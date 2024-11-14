#include<cstdio>
#define N 1005
int n,r,x,y,ans,a[N],f[N],sz[N];
int main(){
	while(scanf("%d%d",&n,&r)!=EOF){
		if((!n)&&(!r)) return 0;
		ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) ans+=a[i];
		for(int i=1;i<=n;i++) sz[i]=1;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			f[y]=x;
		}
		for(int i=1;i<=n;i++){
			x=0;
			for(int j=1;j<=n;j++){
				if((j!=r)&&((!x)||(a[x]*sz[j]<a[j]*sz[x]))) x=j;
			}
			y=f[x];
			ans+=sz[y]*a[x];
			for(int j=1;j<=n;j++){
				if(f[j]==x) f[j]=y;
			}
			f[x]=y;
			a[y]+=a[x];
			a[x]=0;
			sz[y]+=sz[x];
		}
		printf("%d\n",ans);
	}
}


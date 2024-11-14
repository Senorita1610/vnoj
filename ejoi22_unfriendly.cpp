#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+10;
int f[maxn][6],pre[maxn][6],b[10],siz[maxn];
int ans,n,T;
ll a[maxn];
void solve(){
	ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=5;i++) b[i]=0;
	for(int i=0;i<=n;i++){
		siz[i]=0;
		for(int j=0;j<=5;j++) pre[i][j]=f[i][j]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			int x=b[j];
			if(a[i]==a[x]) continue;
			pre[i][++siz[i]]=x;
			for(int k=0;k<=siz[x];k++){
				if(a[pre[x][k]]!=a[i]){
					f[i][siz[i]]=max(f[x][k]+1,f[i][siz[i]]);
					ans=max(ans,f[i][siz[i]]);
				}
			}
		}
		bool flag=1;
		for(int j=0;j<=5;j++){
			if(a[b[j]]==a[i]){
				flag=0;
				b[j]=i;
				break;
			}
		}
		if(flag) b[1]=i;
		sort(b+1,b+1+5);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}


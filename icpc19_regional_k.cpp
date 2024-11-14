#include<bits/stdc++.h>
using namespace std;
#define Maxn 307
int n;
int f[Maxn][Maxn][2],op[Maxn][Maxn][2];
int a[Maxn];
int stk[Maxn];
int cnt=0;
int tot=0;
pair<int,int>ans[Maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(op,0,sizeof(op));
	for(int i=1;i<=n;i++) f[i][i][0]=0,f[i][i][1]=0;
	for(int l=1;l<n;l++){
		for(int i=1;i+l<=n;i++){
			int j=i+l;
			for(int t=0;t<2;t++){
				f[i][j][t]=307;
				if(f[i][j-1][t]+2<f[i][j][t]){
					f[i][j][t]=f[i][j-1][t]+2;
					op[i][j][t]=0;
				}
				if(f[i+1][j][t]+2<f[i][j][t]){
					f[i][j][t]=f[i+1][j][t]+2;
					op[i][j][t]=1;
				}
				if(t==0){
					bool flag=true;
					for(int k=i+1;k<=j;k++){
						if(a[i]>a[k]) flag=false;
					}
					if(flag){
						if(f[i+1][j][t]<f[i][j][t]){
							f[i][j][t]=f[i+1][j][t];
							op[i][j][t]=1;
						}
					}
					flag=true;
					for(int k=i;k<=j-1;k++){
						if(a[k]>a[j]) flag=false;
					}
					if(flag){
						if(f[i][j-1][t]<f[i][j][t]){
							f[i][j][t]=f[i][j-1][t];
							op[i][j][t]=0;
						}
					}
				}
				else{
					bool flag=true;
					for(int k=i+1;k<=j;k++){
						if(a[i]<a[k]) flag=false;
					}
					if(flag){
						if(f[i+1][j][t]<f[i][j][t]){
							f[i][j][t]=f[i+1][j][t];
							op[i][j][t]=1;
						}
					}
					flag=true;
					for(int k=i;k<=j-1;k++){
						if(a[k]<a[j]) flag=false;
					}
					if(flag){
						if(f[i][j-1][t]<f[i][j][t]){
							f[i][j][t]=f[i][j-1][t];
							op[i][j][t]=0;
						}
					}
				}
			}
			if(f[i][j][0]+1<f[i][j][1]){
				f[i][j][1]=f[i][j][0]+1;
				op[i][j][1]=-1;
			}
			if(f[i][j][1]+1<f[i][j][0]){
				f[i][j][0]=f[i][j][1]+1;
				op[i][j][0]=-1;
			}
		}
	}
	cnt=0;
	int lx=1,rx=n,p=0;
	while(lx<rx){
		int q=op[lx][rx][p];
		if(q==0) --rx;
		else if(q==1)++lx;
		else if(q==-1) p=1-p;
		stk[++cnt]=q;
	}
	for(int k=cnt;k;k--){
		int q=stk[k];
		if(q==0){
			if(p==0){
				int pos=lx;
				while(pos<=rx&&a[pos]<a[rx+1]) ++pos;
				if(pos<rx) ans[++tot]=make_pair(pos,rx);
				if(pos<rx+1) ans[++tot]=make_pair(pos,rx+1);
			}else{
				int pos=lx;
				while(pos<=rx&&a[pos]>a[rx+1]) ++pos;
				if(pos<rx) ans[++tot]=make_pair(pos,rx);
				if(pos<rx+1) ans[++tot]=make_pair(pos,rx+1);
			}
			++rx;
		}
		else if(q==1){
			if(p==0){
				int pos=rx;
				while(pos>=lx&&a[pos]>a[lx-1]) --pos;
				if(lx<pos) ans[++tot]=make_pair(lx,pos);
				if(lx-1<pos) ans[++tot]=make_pair(lx-1,pos);
			}else{
				int pos=rx;
				while(pos>=lx&&a[pos]<a[lx-1]) --pos;
				if(lx<pos) ans[++tot]=make_pair(lx,pos);
				if(lx-1<pos) ans[++tot]=make_pair(lx-1,pos);
			}
			--lx;
		}else{
			if(lx<rx) ans[++tot]=make_pair(lx,rx);
			p=1-p;
		}
		sort(a+lx,a+rx+1);
		if(p==1){
			for(int i=lx;i<lx+rx-i;i++){
				swap(a[i],a[lx+rx-i]);
			}
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}


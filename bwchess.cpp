#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,ha,hb,f[(1<<24)+5],w[20][20];
char ch[20][20];
struct node{
	int x,y,j;
}a[20],b[20];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) scanf("%d",&w[i][j]);
	}
	memset(f,63,sizeof(f));
	f[(1<<n)-1]=0;
	for(int i=(1<<n)-1;i<(1<<(n<<1));i++){
		if(f[i]==inf) continue;
		ha=hb=0;
		for(int j=0,x=0,y=1;j<(n<<1);j++){
			if(j&&(i>>j-1&1)&&!(i>>j&1)){
				if(ch[x][y]=='W') a[++ha]=(node){x,y,j-1};
				else b[++hb]=(node){x,y,j-1};
				f[i^(3<<j-1)]=min(f[i^(3<<j-1)],f[i]+w[x][y]);
			}
			if(i>>j&1) x++;
			else y++;
		}
		for(int j=1;j<=ha;j++){
			for(int k=1;k<=hb;k++){
				int tmp=i^(3<<a[j].j)^(3<<b[k].j);
				f[tmp]=min(f[tmp],f[i]+abs(w[a[j].x][a[j].y]-w[b[k].x][b[k].y]));
			}
		}
	}
	printf("%d",f[((1<<n)-1)<<n]);
	return 0;
}


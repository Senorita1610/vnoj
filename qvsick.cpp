#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const ll lim=1e9;
const int MN=5200;
const int v[10][4]={{0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},{0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}};
int p[MN][4],id[31][20][14][11],trans[MN][10],d[19],tot;
ll A,B,L,R,val[MN];
ll f[19][MN][2],res[19][10][MN];
bool vis[19][MN][2];
typedef pair<int,int>pii;
#define fi first
#define se second
queue<pii>q[MN];
int calc(ll x){
	reg ll t=x;reg int n=0;
	while(t)d[++n]=t%10,t/=10;
	reverse(d+1,d+1+n);
	for(reg int i=1;i<=d[1];i++){
		f[1][id[v[i][0]][v[i][1]][v[i][2]][v[i][3]]][i==d[1]]=1;
		q[1].push(make_pair(id[v[i][0]][v[i][1]][v[i][2]][v[i][3]],i==d[1]));
	}
	for(reg int i=1;i<n;i++)
		while(!q[i].empty()){
			reg pii t=q[i].front();q[i].pop();
			if(!t.se){
				for(reg int k=1;k<10;k++)
					if(trans[t.fi][k]){
						f[i+1][trans[t.fi][k]][0]+=f[i][t.fi][0];
						if(!vis[i+1][trans[t.fi][k]][0]){
							vis[i+1][trans[t.fi][k]][0]=true;
							q[i+1].push(make_pair(trans[t.fi][k],0));
						}
					}
			}
			else{
				for(reg int k=1;k<=d[i+1];k++)
					if(trans[t.fi][k]){
						f[i+1][trans[t.fi][k]][k==d[i+1]]+=f[i][t.fi][1];
						if(!vis[i+1][trans[t.fi][k]][k==d[i+1]]){
							vis[i+1][trans[t.fi][k]][k==d[i+1]]=true;
							q[i+1].push(make_pair(trans[t.fi][k],k==d[i+1]));
						}
					}
			}
			f[i][t.fi][t.se]=vis[i][t.fi][t.se]=0;
		}
	return n;
}
ll solve(int idx,ll x){
	if(!x)return 0;
	reg int n=0;reg ll t=x,Ans=0;
	while(t)d[++n]=t%10,t/=10;
	for(reg int i=n;i;i--)Ans+=res[i-1][1][idx];
	reg int v1=0,v2=0,v3=0,v4=0;
	for(reg int i=1;i<=n;i++){
		v1+=v[d[i]][0];v2+=v[d[i]][1];
		v3+=v[d[i]][2];v4+=v[d[i]][3];
		if(!d[i]){v1=v2=v3=v4=-1;break;}
	}
	if(v1==p[idx][0]&&v2==p[idx][1]&&v3==p[idx][2]&&v4==p[idx][3])Ans++;
	v1=p[idx][0],v2=p[idx][1],v3=p[idx][2],v4=p[idx][3];
	for(reg int i=n;i;i--){
		if(d[i]>1)Ans+=res[i-1][d[i]][idx];
		v1-=v[d[i]][0];v2-=v[d[i]][1];
		v3-=v[d[i]][2];v4-=v[d[i]][3];
		if(v1<0||v2<0||v3<0||v4<0||!d[i])break;
		idx=id[v1][v2][v3][v4];
	}
	return Ans;
}
int main(){
	reg int i,j,k,l;
	reg ll a,b,c,d,Ans=0;
	for(i=0,a=1;a<=lim;i++,a*=2)
		for(j=0,b=1;a*b<=lim;j++,b*=3)
			for(k=0,c=1;a*b*c<=lim;k++,c*=5)
				for(l=0,d=1;a*b*c*d<=lim;l++,d*=7){
					val[++tot]=a*b*c*d;
					p[tot][0]=i;p[tot][1]=j;
					p[tot][2]=k;p[tot][3]=l;
					id[i][j][k][l]=tot;
				}
	for(reg int i=1;i<=tot;i++){
		reg int v1=p[i][0],v2=p[i][1],v3=p[i][2],v4=p[i][3],t1,t2,t3,t4;
		for(reg int j=1;j<10;j++){
			t1=v1+v[j][0];t2=v2+v[j][1];
			t3=v3+v[j][2];t4=v4+v[j][3];
			if(t1>29||t2>18||t3>12||t4>9)continue;
			trans[i][j]=id[t1][t2][t3][t4];
		}
	}
	a=1;
	for(reg int i=0;i<18;i++,a*=10){
		b=a;
		for(reg int j=1;j<10;j++,b+=a){
			reg int n=calc(b-1);
			for(reg int k=1;k<=tot;k++){
				res[i][j][k]=f[n][k][0]+f[n][k][1];
				f[n][k][0]=f[n][k][1]=0;
				vis[n][k][0]=vis[n][k][1]=0;
			}
			while(!q[n].empty())q[n].pop();
		}
	}
	reg int n=calc(a-1);
	for(reg int i=1;i<=tot;i++){
		res[18][1][i]=f[n][i][0]+f[n][i][1];
		f[n][i][0]=f[n][i][1]=0;
		vis[n][i][0]=vis[n][i][1]=0;
	}
	scanf("%lld%lld",&A,&B);
	for(reg int i=1;i<=tot;i++){
		L=(A+val[i]-1)/val[i];R=B/val[i];
		if(L>R)continue;
		Ans+=solve(i,R)-solve(i,L-1);
	}
	printf("%lld\n",Ans);Ans=0;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,m;
int xm,ym,xz,yz;
char a[26][26];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int f[4];
bool flag[26][26];

void dfs(int lx,int ly,int x,int y){
	if(x<1||x>n||y<1||y>m||flag[x][y]) return;
	flag[x][y]=1;
	if(a[x][y]=='.'){
		cout<<x<<' '<<y<<' ';
		for(int i=0;i<=3;i++){
			int px=x+dx[i],py=y+dy[i];
			if(i==0&&(a[px][py]=='|'||a[px][py]=='+'||a[px][py]=='1'||a[px][py]=='4')) f[i]=1;
			if(i==1&&(a[px][py]=='|'||a[px][py]=='+'||a[px][py]=='2'||a[px][py]=='3')) f[i]=1;
			if(i==2&&(a[px][py]=='-'||a[px][py]=='+'||a[px][py]=='1'||a[px][py]=='2')) f[i]=1;
			if(i==3&&(a[px][py]=='-'||a[px][py]=='+'||a[px][py]=='3'||a[px][py]=='4')) f[i]=1;
            if(a[px][py]=='M'||a[px][py]=='Z') f[i]=1;
		}
		if(f[0]==1&&f[1]==1&&f[2]==0&&f[3]==0) {cout<<'|';exit(0);}
		if(f[0]==0&&f[1]==0&&f[2]==1&&f[3]==1) {cout<<'-';exit(0);}
		if(f[0]==1&&f[1]==1&&f[2]==1&&f[3]==1) {cout<<'+';exit(0);}
		if(f[0]==0&&f[1]==1&&f[2]==0&&f[3]==1) {cout<<'1';exit(0);}
		if(f[0]==1&&f[1]==0&&f[2]==0&&f[3]==1) {cout<<'2';exit(0);}
		if(f[0]==1&&f[1]==0&&f[2]==1&&f[3]==0) {cout<<'3';exit(0);}
		if(f[0]==0&&f[1]==1&&f[2]==1&&f[3]==0) {cout<<'4';exit(0);}
	}
	if(a[x][y]=='|'){
		if(lx>x) dfs(x,y,x-1,y);
		else dfs(x,y,x+1,y);
	}
	else if(a[x][y]=='-'){
		if(ly<y) dfs(x,y,x,y+1);
		else dfs(x,y,x,y-1);
	}
	else if(a[x][y]=='+'){
		if(lx>x) {dfs(x,y,x-1,y),dfs(x,y,x,y-1),dfs(x,y,x,y+1);}
		else if(lx<x) {dfs(x,y,x+1,y),dfs(x,y,x,y-1),dfs(x,y,x,y+1);}
		else if(ly<y) {dfs(x,y,x-1,y),dfs(x,y,x+1,y),dfs(x,y,x,y+1);}
		else if(ly>y) {dfs(x,y,x,y-1),dfs(x,y,x+1,y),dfs(x,y,x-1,y);}
	}
	else if(a[x][y]=='1') {
		if(ly>y) dfs(x,y,x+1,y);
		else if(lx>x) dfs(x,y,x,y+1);
	}
	else if(a[x][y]=='2') {
		if(lx<x) dfs(x,y,x,y+1);
		else dfs(x,y,x-1,y);
	}
	else if(a[x][y]=='3'){
		if(ly<y) dfs(x,y,x-1,y);
		else dfs(x,y,x,y-1);
	}
	else if(a[x][y]=='4'){
		if(ly<y) dfs(x,y,x+1,y);
		else dfs(x,y,x,y-1);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='Z') xz=i,yz=j;
			if(a[i][j]=='M') xm=i,ym=j;
		}
	} 
	bool fla=0; 
	for(int i=0;i<=3;i++){
		int px=xm+dx[i],py=ym+dy[i];
		if(i==0&&(a[px][py]=='|'||a[px][py]=='+'||a[px][py]=='1'||a[px][py]=='4')) dfs(xm,ym,px,py),fla=1;
		if(i==1&&(a[px][py]=='|'||a[px][py]=='+'||a[px][py]=='2'||a[px][py]=='3')) dfs(xm,ym,px,py),fla=1;
		if(i==2&&(a[px][py]=='-'||a[px][py]=='+'||a[px][py]=='1'||a[px][py]=='2')) dfs(xm,ym,px,py),fla=1;
		if(i==3&&(a[px][py]=='-'||a[px][py]=='+'||a[px][py]=='3'||a[px][py]=='4')) dfs(xm,ym,px,py),fla=1;
	}
	if(fla){ 
		if(flag[xz-2][yz]==1) cout<<'|';
		else if(flag[xz+2][yz]==1) cout<<'|';
		else if(flag[xz][yz+2]==1) cout<<'-';
		else if(flag[xz][yz-2]==1) cout<<'-';
		else if(flag[xz-1][yz-1]==1) {
			if(a[xz][yz-1]=='.') cout<<2;
			else cout<<4;
		}
		else if(flag[xz-1][yz+1]==1) {
			if(a[xz-1][yz]=='.') cout<<1;
			else cout<<3;
		}
		else if(flag[xz+1][yz-1]==1) {
			if(a[xz][yz-1]=='.') cout<<1;
			else cout<<3;
		}
		else if(flag[xz+1][yz+1]==1) {
			if(a[xz][yz+1]=='.') cout<<4;
			else cout<<2;
		}
	}
	else{
		for(int i=0;i<=3;i++){
			int px=xz+dx[i],py=yz+dy[i];
			if(i==0&&(a[px][py]=='|'||a[px][py]=='+'||a[px][py]=='1'||a[px][py]=='4')) dfs(xz,yz,px,py),fla=1;
			if(i==1&&(a[px][py]=='|'||a[px][py]=='+'||a[px][py]=='2'||a[px][py]=='3')) dfs(xz,yz,px,py),fla=1;
			if(i==2&&(a[px][py]=='-'||a[px][py]=='+'||a[px][py]=='1'||a[px][py]=='2')) dfs(xz,yz,px,py),fla=1;
			if(i==3&&(a[px][py]=='-'||a[px][py]=='+'||a[px][py]=='3'||a[px][py]=='4')) dfs(xz,yz,px,py),fla=1;
		}
		if(fla){
			if(flag[xm-2][ym]==1) cout<<'|';
			else if(flag[xm+2][ym]==1) cout<<'|';
			else if(flag[xm][ym+2]==1) cout<<'-';
			else if(flag[xm][ym-2]==1) cout<<'-';
			else if(flag[xm-1][ym-1]==1) {
				if(a[xm][ym-1]=='.') cout<<2;
				else cout<<4;
			}
			else if(flag[xm-1][ym+1]==1) {
				if(a[xm-1][ym]=='.') cout<<1;
				else cout<<3;
			}
			else if(flag[xm+1][ym-1]==1) {
				if(a[xm][ym-1]=='.') cout<<1;
				else cout<<3;
			}
			else if(flag[xm+1][ym+1]==1) {
				if(a[xm][ym+1]=='.') cout<<4;
				else cout<<2;
			}
		}
		else{
            flag[xz][yz]=flag[xm][ym]=1;
			if(flag[xm-2][ym]==1) cout<<xm-1<<' '<<ym<<' '<<'|';
			else if(flag[xm+2][ym]==1) cout<<xm+1<<' '<<ym<<' '<<'|';
			else if(flag[xm][ym+2]==1) cout<<xm<<' '<<ym+1<<' '<<'-';
			else if(flag[xm][ym-2]==1) cout<<xm<<' '<<ym-1<<' '<<'-';
			else if(flag[xm-1][ym-1]==1) {
				if(a[xm][ym-1]=='.') cout<<xm<<' '<<ym-1<<' '<<2;
				else cout<<xm-1<<' '<<ym<<' '<<4;
			}
			else if(flag[xm-1][ym+1]==1) {
				if(a[xm-1][ym]=='.') cout<<xm-1<<' '<<ym<<' '<<1;
				else cout<<xm<<' '<<ym+1<<' '<<3;
			}
			else if(flag[xm+1][ym-1]==1) {
				if(a[xm][ym-1]=='.') cout<<xm<<' '<<ym-1<<' '<<1;
				else cout<<xm+1<<' '<<ym<<' '<<3;
			}
			else if(flag[xm+1][ym+1]==1) {
				if(a[xm][ym+1]=='.') cout<<xm<<' '<<ym+1<<' '<<4;
				else cout<<xm+1<<' '<<ym<<' '<<2;
			}
		}
	}
	return 0;
}


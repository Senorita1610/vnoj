#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int vis[15][15],idx[15][15][5],shu[15][15],now,ans;
int fx[10]={0,1,1,1,4,4,4,7,7,7},fy[10]={0,1,4,7,1,4,7,1,4,7};
signed main(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=9;i++){
		int sum=0;
		for(int j=1;j<=9;j++){
			sum+=a[i][j]-'0';
		}
		if(sum%2==1){
			now++;
			for(int j=1;j<=9;j++){
				vis[i][j]++;
				idx[i][j][1]=1;
			}
		}
	}
	for(int i=1;i<=9;i++){
		int sum=0;
		for(int j=1;j<=9;j++){
			sum+=a[j][i]-'0';
		}
		if(sum%2==1){
			now++;
			for(int j=1;j<=9;j++){
				vis[j][i]++;
				idx[j][i][2]=1;
			}
		}
	}
	for(int k=1;k<=9;k++){
		int x=fx[k],y=fy[k],sum=0;
		for(int i=x;i<=x+2;i++){
			for(int j=y;j<=y+2;j++){
				sum+=a[i][j]-'0';
				shu[i][j]=k;
			}
		}
		if(sum%2==1){
			now++;
			for(int i=x;i<=x+2;i++){
				for(int j=y;j<=y+2;j++){
					vis[i][j]++,idx[i][j][3]=1;
				}
			}
		}
	}
	bool flag=0;
	while(now>0){
		flag=0;
		int start=now;
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				if(vis[i][j]==3){
					now-=3,ans++;
					for(int k=1;k<=9;k++){
						vis[i][k]--,idx[i][k][1]=0;
					}
					for(int k=1;k<=9;k++){
						vis[k][j]--,idx[k][j][2]=0;
					}
					int s=shu[i][j],x=fx[s],y=fy[s];
					for(int x1=x;x1<=x+2;x1++){
						for(int y1=y;y1<=y+2;y1++){
							vis[x1][y1]--,idx[x1][y1][3]=0;
						}
					}
				}
			}
		}
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				if(vis[i][j]==2){
					now--,ans++;
					int op=6;
					if(idx[i][j][1]==1){
						op-=1;
						for(int k=1;k<=9;k++){
							vis[i][k]--,idx[i][k][1]=0;
						}
					}
					if(idx[i][j][2]==1){
						op-=2;
						for(int k=1;k<=9;k++){
							vis[k][j]--,idx[k][j][2]=0;
						}
					}
					if(idx[i][j][3]==1){
						op-=3;
						int s=shu[i][j],x=fx[s],y=fy[s];
						for(int x1=x;x1<=x+2;x1++){
							for(int y1=y;y1<=y+2;y1++){
								vis[x1][y1]--,idx[x1][y1][3]=0;
							}
						}
					}
					if(op==1){
						for(int k=1;k<=9;k++){
							vis[i][k]++,idx[i][k][1]=1;
						}
					}
					if(op==2){
						for(int k=1;k<=9;k++){
							vis[k][j]++,idx[k][j][2]=1;
						}
					}
					if(op==3){
						int x=i,y=j;
						for(int x1=x;x1<=x+2;x1++){
							for(int y1=y;y1<=y+2;y1++){
								vis[x1][y1]++,idx[x1][y1][3]=1;
							}
						}
					}
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		if(start==now) break;
	}
	cout<<ans+now;
	return 0;
}


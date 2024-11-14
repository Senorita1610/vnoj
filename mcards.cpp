#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
#include<cstring>
#include<set>
using namespace std;
struct pp{
	int x,y;
}p[444];
int c,n,P[5],dp[444];
int lis(){
	int res=0;
	for(int i=0;i<c*n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(P[p[j].x]<P[p[i].x]){
				dp[i]=max(dp[j]+1,dp[i]);
			}
			else if(P[p[j].x]==P[p[i].x]){
				if(p[j].y<p[i].y){
					dp[i]=max(dp[j]+1,dp[i]);
				}
			}
		}
		res=max(res,dp[i]);
	}
	return res;
}
int main(){
	scanf("%d%d",&c,&n);
	for(int i=0;i<n*c;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	for(int i=1;i<=4;i++) P[i]=i;
	int ans=c*n;
	do{
		ans=min(ans,c*n-lis());
	}while(next_permutation(P+1,P+1+c));
	printf("%d\n",ans);
}


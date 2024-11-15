#include<stdio.h>
#include<string.h>
int g[19][3]={
	3,4,1,
	4,5,2,
	5,6,-1,
	7,8,4,
	8,9,5,
	9,10,6,
	10,11,-1,
	-1,12,8,
	12,13,9,
	13,14,10,
	14,15,11,
	15,-1,-1,
	-1,16,13,
	16,17,14,
	17,18,15,
	18,-1,-1,
	-1,-1,17,
	-1,-1,18,
	-1,-1,-1
};
int dp[600000][2];
int find(int s,int id){
	if(dp[s][id]!=-1) return dp[s][id];
	int tts=s;
	if(s==0) return dp[s][id]=0;
	s=tts;
	for(int i=0;i<19;i++){
		if((s&(1<<(18-i)))!=0){
			for(int j=0;j<3;j++){
				int now=i;
				int ts=s;
				while(now!=-1&&(((s&(1<<(18-now)))!=0))){
					ts-=(1<<(18-now));
					if(find(ts,1-id)==0) return dp[s][id]=1;
					now=g[now][j];
				}
			}
		}
	}
	return dp[s][id]=0;
}
char c[100];
int main(){
	while(scanf(" %c",&c[0])==1){
		for(int i=1;i<19;i++){
			scanf(" %c",&c[i]);
		}
		memset(dp,-1,sizeof(dp));
		int num=0;
		for(int i=0;i<19;i++){
			if(c[i]=='.') num=num*2;
			else num=num*2+1;
		}
		if(find(num,0)) puts("Karlsson");
		else puts("Lillebror");
	}
	return 0;
}


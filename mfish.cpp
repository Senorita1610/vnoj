#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int b[N],d[N],a[N],dp[2][N],n,m,idx[N],st[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i),a[i]+=a[i-1];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		scanf("%d%d",b+i,d+i),idx[i]=i,st[i]=max(1,b[i]-d[i]+1);
	}
	int ed,cur,left=0,nxt;
	sort(idx,idx+m,[m](int d,int c){
		return b[d]<b[c];
	});
	bool t=(m-1)%2;
	idx[m]=m;
	b[m]=n+1;
	for(int i=m-1;i>-1;i--,t=!t){
		cur=idx[i];
		nxt=idx[i+1];
		ed=b[cur];
		for(int j=ed;j>=st[cur];j--){
			if(j+d[cur]-1<b[nxt]) dp[t][j]=max(dp[!t][max(j+d[cur],st[nxt])]+a[j+d[cur]-1]-a[j-1],dp[t][j+1]);
		}
	}
	cout<<dp[0][st[cur]];
}


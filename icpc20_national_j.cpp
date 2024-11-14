#include<bits/stdc++.h>
using namespace std;
int n;
int mxl[20],mxr[20],a[20];
long long res;
void chk(){
	for(int i=1;i<=n;i++){
		mxl[i]=max(mxl[i-1],a[i]);
	}
	long long ans=0;
	for(int i=n;i>=1;i--){
		mxr[i]=max(mxr[i+1],a[i]);
		ans+=max(0,min(mxr[i+1],mxl[i-1])-a[i]);
	}
	res=max(res,ans);
}
void dfs(int x,int k){
	if(x==n){
		a[x]+=k;
		chk();
		a[x]-=k;
		return;
	}
	for(int i=0;i<=k;i++){
		dfs(x+1,k-i);
		a[x]++;
	}
	a[x]-=k+1;
}
int main(){
	int k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,k);
	printf("%lld\n",res);
	return 0;
}


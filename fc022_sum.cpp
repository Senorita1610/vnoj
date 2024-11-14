#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=20,maxs=150;
int f[maxn][maxs],digit[maxn];
int a,b,s;
int dfs(int pos,int pre,int limit,int lead){
	if(pos==0&&pre==s) return 1;
	if(pre+pos*9<s) return 0;	
	if(!lead&&!limit&&f[pos][pre]!=-1) return f[pos][pre];
	int sum=0,up;
	if(limit) up=digit[pos];
	else up=9;
	for(int i=0;i<=up;i++){
		if(pre+i>s) break;
		sum+=dfs(pos-1,pre+i,(limit&&i==up),lead&&(i==0));
	}
	if(!limit&&!lead) f[pos][pre]=sum;
	return sum; 
}
int solve(int x){
	memset(f,-1,sizeof(f));
	memset(digit,0,sizeof(digit));
	int cnt=0;
	while(x){
		digit[++cnt]=x%10;
		x/=10;
	}
	return dfs(cnt,0,1,1);
}
signed main(){
	scanf("%lld%lld%lld",&a,&b,&s);
	int x=solve(a-1);
	printf("%lld\n",solve(b)-x);
	int l=a,r=b,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(solve(mid)-x>0){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}


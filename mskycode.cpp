#include<cstdio>
#include<cstring>
const int M=10005;
long long C[M];
int mu[M],A[M];
int n;
int main(){
	for(int i=mu[1]=1;i<M;i++) if(mu[i]) for(int j=i+i;j<M;j+=i) mu[j]-=mu[i];
	for(int i=4;i<M;i++) C[i]=1LL*i*(i-1)*(i-2)*(i-3)/24;
	while(~scanf("%d",&n)){
		memset(A,0,sizeof(A));
		for(int i=0,x;i<n;i++) scanf("%d",&x),++A[x];
		long long ans=0;
		for(int i=1;i<M;i++) if(mu[i]){
			int cnt=0;
			for(int j=i;j<M;j+=i) cnt+=A[j];
			ans+=C[cnt]*mu[i]; 
		}
		printf("%lld\n",ans);
	}
	return 0;
}


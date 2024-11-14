#include<bits/stdc++.h>
using namespace std;
int n;
int a[100050];
double dp[100050][30];
int main(){
	int ls=0,N,first,last;
	scanf("%d",&n);
	for(ls=0,N=1;N<n;ls++,N*=2);
	for(int i=0;i<n;i++) scanf("%d",&a[N-n+i]);
	sort(a+(N-n+1),a+N);
	for(int i=0;i<N-n;i++) a[2*i]=a[N-n+i],a[2*i+1]=0;
	for(int i=0;i<N;i++)dp[i][0]=1;
	for(int r=0;r<ls;r++){
		for(int i=0;i<N;i++){
			dp[i][r+1]=0;
			if(a[i]==0) continue;
			first=(((i>>r)^1)<<r);
			last=first+(1<<r);
			for(int j=first;j<last;j++){
				dp[i][r+1]+=dp[j][r]*1.0*a[i]/(a[i]+a[j]);
			}
			dp[i][r+1]*=dp[i][r];
		}
	}
	printf("%.12lf\n",dp[0][ls]);
	return 0;
}


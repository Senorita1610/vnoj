#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1001
bitset<mx>bt;
int prime[mx];
int e=-1;
void sieve(){
	bt[0]=bt[1]=1;
	prime[++e]=2;
	for(int i=4;i<mx;i+=2) bt[i]=1;
	for(int i=3;i*i<=mx;i+=2){
		if(!bt[i]){
			prime[++e]=i;
			for(int j=i*i;j<mx;j+=i) bt[j]=1;
		}
	}
	for(int i=31;i<mx;i+=2){
		if(!bt[i]) prime[++e]=i;
	}
}
int F(int n){
	int r=n;
	int i=0;
	while(i<=e&&prime[i]*prime[i]<=n){
		if(n%prime[i]==0) r-=r/prime[i];
		while(n%prime[i]==0){
			n/=prime[i];
		}
		i++;
	}
	if(n>1) r-=r/n;
	return r;
}
int main(){
	sieve();
	int tc,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		printf("%d\n",F(n));
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn];
int a[maxn],b[maxn],c[maxn];
int calc(int l,int r){
	return max(a[r]-a[l-1],max(b[r]-b[l-1],c[r]-c[l-1]));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='R');
		for(int i=1;i<=n;i++) b[i]=b[i-1]+(s[i]=='P');
		for(int i=1;i<=n;i++) c[i]=c[i-1]+(s[i]=='S');
		int mx=0,round=0;
		for(int i=2;i<=n;i++){
			int sum=0;
			for(int j=1;j<=n;j+=i){
				sum+=calc(j,min(j+i-1,n));
			}
			if(sum>=mx) mx=sum,round=i;
		}
		printf("%d\n",round);
	}
}


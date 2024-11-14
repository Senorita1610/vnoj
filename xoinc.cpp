#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n;
int c[N];int f[N][N];
int sum[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	sum[n]=c[n];
	for(int i=n-1;i;i--) sum[i]=sum[i+1]+c[i];
	for(int i=n;i>=1;i--){
		f[i][0]=0;
		for(int j=1;j+i-1<=n;j++){
			if(n-i+1<=j){
				f[i][j]=sum[i];
				continue;
			}
			f[i][j]=f[i][j-1];
			if(n-(i+j-1)<=(j<<1)){
				if(sum[i]-sum[i+j]>f[i][j]) f[i][j]=sum[i]-sum[i+j];
			}
			else{
				if(sum[i]-f[i+j][j<<1]>f[i][j]) f[i][j]=sum[i]-f[i+j][j<<1];
			}
		}
	}
	printf("%d\n",f[1][2]);
	return 0;
}


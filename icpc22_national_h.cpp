#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long N=10,MOD=998244353;
long long n;
struct Matrix{
	long long M[N][N];
}c;
Matrix Mul(Matrix a,Matrix b){
	Matrix c;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			c.M[i][j]=0;
			for(int k=0;k<10;k++){
				c.M[i][j]=(c.M[i][j]+a.M[i][k]*b.M[k][j])%MOD;
			}
		}
	}
	return c;
}
Matrix Pow(Matrix a,long long k){
	Matrix ans;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			ans.M[i][j]=i==j;
		}
	}	
	while(k){
		if(k%2) ans=Mul(ans,a);
		a=Mul(a,a);
		k/=2;
	}
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	c={1,1,1,1,1,0,0,0,0,0,
	   1,0,0,0,1,0,0,0,0,0,
	   1,0,0,0,0,0,0,0,0,0,
	   1,0,1,0,0,0,0,0,0,0,
	   1,0,0,0,0,0,0,0,0,0,
	   0,3,3,3,3,1,1,1,1,1,
	   0,0,0,0,3,1,0,0,0,1,
	   0,0,0,0,0,1,0,0,0,0,
	   0,0,3,0,0,1,0,1,0,0,
	   0,0,0,0,0,1,0,0,0,0
	};
	c=Pow(c,n-1);
	long long ans=c.M[5][0]+c.M[5][1]+c.M[5][2]+c.M[5][3]+c.M[5][4];
	cout<<ans%MOD;
	return 0;
}


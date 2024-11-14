#include<bits/stdc++.h>

using namespace std;
int n, m;
long long k;
const int p = 1e9+7;
struct matrix{
	int a[105][105], n, m;
	matrix(int n, int m){
		this->n = n, this->m = m;
		memset(a,0,sizeof(a));
	}
	void setNum(int x){
		for (int i = 1; i <= min(n,m); i++) a[i][i] = x;
	};
	int getSum(){
		int res =0;
		for (int i = 1; i<= n; i++) for (int j = 1; j<= m; j++) (res+=a[i][j])%=p;
		return res;
	}
	matrix operator*(matrix other){
		matrix res = matrix(n,other.m);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= other.m; j++) for (int k = 1; k <= m; k++) (res.a[i][j] += 1ll*a[i][k]*other.a[k][j]%p)%=p;
		return res;
	}
};
matrix getPow(matrix a, long long n){
	matrix res = matrix(a.n,a.m);
	res.setNum(1);
	while (n){
		if (n&1) res = res*a;
		a = a*a;
		n >>= 1;
	}
	return res;
}

int main(){
	
	cin >> n >> m >> k;
	matrix base = matrix(n,n);
	for (int i = 1, u, v; i <= m; i++){
		cin >> u >> v;
		base.a[u][v] = 1; 
	}
	cout << getPow(base,k).getSum();
	
	return 0;
}


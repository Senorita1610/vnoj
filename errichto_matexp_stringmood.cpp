#include<bits/stdc++.h>
using namespace std;
const int p = 1e9+7;
struct matrix{
	int a[2][2];
	matrix(){
		memset(a,0,sizeof(a));
	}
	void setNum(){
		for (int i =0; i < 2; i++) a[i][i] = 1;
	}
	matrix operator*(matrix other){
		matrix res = matrix();
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) (res.a[i][j] += 1ll*a[i][k]*other.a[k][j]%p)%=p;
		return res;
	}
};
matrix getPow(matrix a, long long n){
	matrix res = matrix();
	res.setNum();
	while (n){
		if (n&1) res = res*a;
		a = a*a;
		n >>= 1;
	}
	return res;
}

int main(){
	matrix base = matrix();
	base.a[0][0] = 19; base.a[0][1] = 7;
	base.a[1][0] = 6; base.a[1][1] = 20;
	matrix f0 = matrix();
	f0.a[0][0] = 1;
	long long n;
	cin >> n;
	cout << (f0*getPow(base,n)).a[0][0];
	
	return 0;
}


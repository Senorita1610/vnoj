#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	cin>>n>>m;
	long long d=n*m;
	while(d>n){
		d=d+(d-n-1)/(m-1)-n;
	}
	cout<<d;
	return 0;
}


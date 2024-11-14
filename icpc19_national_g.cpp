#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	int n;
	cin>>n;
	vector<ll>x(n);
	ll res=0;
	for(int i=0;i<n;i++){
		cin>>x[i];
		res+=abs(x[i]);
	}
	sort(x.begin(),x.end());
	vector<ll>sum(n+1);
	for(int i=0;i<n;i++){
		sum[i+1]=sum[i]+x[i];
	}
	auto warp = [&](int lb,int ub){
		int m=(lb+ub)/2;
		return (sum[ub]-sum[m])-x[m]*(ub-m)+x[m]*(m-lb)-(sum[m]-sum[lb]);
	};
	auto dir = [&](int lb,int ub){
		int p=lower_bound(x.begin(),x.end(),0)-x.begin();
		p=max(p,lb);
		p=min(p,ub);
		return -(sum[p]-sum[lb])+(sum[ub]-sum[p]);
	};
	for(int i=0;i<n;i++){
		res=min(res,warp(0,i+1)+dir(i+1,n));
		res=min(res,dir(0,i)+warp(i,n));
	}
	cout<<res<<endl;
	return 0;
}


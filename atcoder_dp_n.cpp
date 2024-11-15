#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,j;
ll ans,sum;
vector<ll>v;
int main(){
	cin>>n;
	v.push_back(444444444444);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	v.push_back(444444444444);
	while(n-->1){
		for(k=1;k<=n;k++){
			if(v[k-1]<v[k+1]) break;
		}
		sum=v[k]+v[k-1];
		for(j=k-1;j>=0;j--){
			if(v[j]>v[k]+v[k-1]) break;
		}
		v.erase(v.begin()+k-1);
		v.erase(v.begin()+k-1);
		v.insert(v.begin()+j+1,sum);
		ans+=sum;
	}
	cout<<ans;
	return 0;
}


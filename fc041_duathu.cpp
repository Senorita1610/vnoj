#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[1005];
int main(){
	int n,k,ans=0,now=0,dis;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
	sort(a,a+n);
	for(int i=0;a[i].first<0&&i<n;i++){
		if(now==0) dis=-a[i].first;
		now+=a[i].second;
		if(now>=k){
			now-=k;
			ans+=dis;
			dis=-a[i].first;
			if(now>=k){
				ans+=(now/k)*dis;
				now%=k;
			}
		}
	}
	if(now) ans+=dis;
	now=0;
	for(int i=n-1;a[i].first>0&&i>=0;i--){
		if(now==0) dis=a[i].first;
		now+=a[i].second;
		if(now>=k){
			now-=k;
			ans+=dis;
			dis=a[i].first;
			if(now>=k){
				ans+=(now/k)*dis;
				now%=k;
			}
		}
	}
	if(now) ans+=dis;
	cout<<ans*2;
}


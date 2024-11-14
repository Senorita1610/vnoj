#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
int const N=5e5;
int const inf=1e9+7;
int diff[N];
int cpy[N];
void solve(){
	int n;
	cin>>n;
	for (int i = 0; i <=100000; ++i)
		diff[i]=-inf;
	diff[0]=0;
	int sm=0;
	for(int e=0;e<n;e++){
		int c;
		cin>>c;
		sm+=c;
		for (int i = 0; i <=100000; ++i)
			cpy[i]=diff[i];
		for(int i=100000;i>=0;i--){
			if(diff[i]<0)
				continue;
			cpy[i+c]=max(diff[i],cpy[i+c]);
			if(i>=c)
				cpy[i-c]=max(diff[i]+c,cpy[i-c]);
			else
				cpy[c-i]=max(diff[i]+i,cpy[c-i]);
		}
		for(int i=0;i<=100000;i++)
			diff[i]=cpy[i];
	}
	cout<<sm-(diff[0])<<endl;
}
 
int main(){
	int t=1;
	// cin>>t;
	while(t--)
		solve();
	return 0;
}


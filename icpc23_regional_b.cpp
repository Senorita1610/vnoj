#include<bits/stdc++.h>
using namespace std;
int solve(){
	int n,m,a[21]={0},x,boo=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int temp=0;
		for(int j=1;j<=m;j++){
			cin>>x;
			a[j]+=x;
			temp+=x;
		}
		if(temp==m||temp==0) boo=0;
	}
	for(int i=1;i<=m;i++){
		if(a[i]==0) boo=0;
	}
	return boo;
}
int main(){
	int n;
	cin>>n;
	for(int t=1;t<=n;t++){
		if(solve()==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}


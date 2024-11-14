#include<bits/stdc++.h>
using namespace std;
int sana(int n,int a,int b,int x,int y){
	if(x>a||y>b) return 0;
	if(x==a&&y==b) return max(x,y)>=n&&abs(x-y)>=2;
	if(max(x,y)>=n&&abs(x-y)>=2) return 0;
	return sana(n,a,b,x+1,y)+sana(n,a,b,x,y+1);
}
void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	cout<<sana(n,a,b,0,0)<<endl;	
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}


#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define str string
using namespace std;
int pp[1000001];
int a[1000001];
int b[1000001];
void solve(){
	int n,c;
	cin>>n>>c;
	str s;
	cin>>s;
	int d=0,l=0;
	for(int i=n-1;i>-1;i--){
		if(s[i]=='b'){
			d++;
			b[i]++;
		}
		if(s[i]=='a'){
			pp[i]+=d;
			l++;
			a[i]++;
		}
		pp[i]+=pp[i+1];
		b[i]+=b[i+1];
		a[i]+=a[i+1];
	}
	int ans=1;
	for(int i=0;i<n;i++){
		l=i;
		int r=n-1;
		while(r-l>1){
			int m=(l+r)>>1;
			int an=pp[i]-pp[m+1]-((a[i]-a[m+1])*(b[m+1]));
			if(an>c) r=m;
			else{
				ans=max(ans,m-i+1);
				l=m;
			}
		}
		int m=r;
		int an=pp[i]-pp[m+1]-((a[i]-a[m+1])*(b[m+1]));
		if(an<=c) ans=max(ans,r-i+1);
		m=l;
		an=pp[i]-pp[m+1]-((a[i]-a[m+1])*(b[m+1]));
		if(an<=c) ans=max(ans,l-i+1);
	}
	cout<<ans;
}
signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}


#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	int x;
	cin>>s>>x;
	long long u=0,v=0,a=1,b=1;
	for(int i=0,n=s.size(),o=0;i<n;i++){
		if(isdigit(s[i])){
			u=u*10+s[i]-'0';
			if(i+x<n) v=v*10+s[i]-'0';
			if(o==1){
				a*=10;
				if(i+x<n) b*=10;
			}
		}
		else o=1;
	}
	u-=v;a-=b;
	long long g=__gcd(u,a);
	u/=g,a/=g;
	cout<<u<<"/"<<a<<endl;
	return 0;
}


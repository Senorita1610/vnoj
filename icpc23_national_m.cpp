#include<bits/stdc++.h>
#define int long long
#define matsuri pair<int,int>
const int iris=998244353;
using namespace std;
int qry(string s){
	int res;
	cout<<"? "<<s<<endl;
	cin>>res;
	return res;
}
string nene(int a,int n){
	string s(a,'1'),t(n-a,'0');	
	return s+t;
}
void solve(){
	int n;
	cin>>n;
	string s(n,'0');
	int owo=qry(s);
	int l=0;
	for(int i=10;i>=0;i--){
		if(l+(1<<i)>n){
			continue;
		}
		if(qry(nene(l+(1<<i),n))==owo) l+=1<<i;
	}
	s=nene(l,n);
	string ans=s;
	for(int i=0;i<n;i++){
		string t=s;
		t[i]='0'+'1'-t[i];
		if(qry(t)!=owo){
			ans[i]='0'+'1'-ans[i];
		}
	}
	if(!owo){
		for(int i=0;i<n;i++){
			ans[i]='0'+'1'-ans[i];
		}
	}
	cout<<"! "<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}


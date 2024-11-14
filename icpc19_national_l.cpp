#include<bits/stdc++.h>
#define for1(i,a,b) for(int i=a;i<=b;i++)
#define for2(i,a,b) for(int i=a;i>=b;i--)
#define int long long
#define sz(a) (int)a.size()
#define pii pair<int,int>
using namespace std;
string op,name,s;
map<string,string>mp;
string solve(int l,int r){
	string res="";
	if(s[l]=='"'){
		for1(i,l+1,r-1) res+=s[i];
		return res;
	}
	if(s[l]!='`'){
		for1(i,l,r) res+=s[i];
		return mp[res];
	}
	int cur=l+1;
	while(cur<r){
		if(s[cur]!='$'||s[cur+1]!='{') res+=s[cur];
		else{
			int cnt=0,pos;
			for1(i,cur+1,r){
				if(s[i]=='{') cnt++;
				if(s[i]=='}') cnt--;
				if(cnt==0){
					pos=i;
					break;
				}
			}
			res+=solve(cur+2,pos-1);
			cur=pos;
		}
		cur++;
	}
	for(auto f:res) if(f=='~') return "~";
	if(sz(res)>10000) return "~";
	return res;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>op&&op!="end."){
		if(op[0]=='v'){
			cin>>name>>s;
			getline(cin,s);
			s.erase(0,1);
			mp[name]=solve(0,sz(s)-2);
		}
		else{
			getline(cin,s);
			s.erase(0,1);
			cout<<solve(0,sz(s)-2)<<endl;
		}
	}
}


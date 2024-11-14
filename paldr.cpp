#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const ll M=1e9+7;
const ll P=137;
char minc=127;
ll mem[1000111];
ll po(ll b,ll p){
	if(mem[p]!=-1) return mem[p];
	if(!p) return mem[p]=1;
	ll pp=po(b,p/2);
	if(p%2) return mem[p]=(b*((pp*pp)%M))%M;
	else return mem[p]=(pp*pp)%M;
}
string s;
bool check(int a,int b){
	return (a>b)||((b-a)%2 && s[a]==s[b] && check(a+1,b-1));
}
bool rol(int b,int i,ll h1,ll h2){
	int ind=b+i;
	if(ind==(int)s.size()) return false;
	h1=h1*P+(s[ind]-minc);
	h2+=(s[ind]-minc)*po(P,i);
	h1%=M;h2%=M;
	if(i%2&&(h1==h2)&&check(b,b+i)) return (b+i+1==(int)s.size())||rol(b+i+1,0,0,0);
	return rol(b,i+1,h1,h2);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	memset(mem,-1,sizeof mem);
	getline(cin,s);
	while(T--){
		getline(cin,s);
		s.erase(std::remove(s.begin(),s.end(),'\n'),s.end());
		minc=127;
		for(char c:s) minc=min(c,minc);
		if(!s.size()||rol(0,0,0,0)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}


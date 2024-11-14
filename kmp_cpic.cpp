#include<bits/stdc++.h>
using namespace std;
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define RFOR(i,b,a) for(int i=b-1;i>=a;i--)
#define MP make_pair
#define PB push_back
#define F first
#define S second
typedef long long LL;
typedef pair<int,int>PII;
typedef vector<int>VI;
const int M=360000;
int p[4*M];
void pi(string& s){
	p[0]=0;
	FOR(i,1,SZ(s)){
		int j=p[i-1];
		while(j!=0&&s[i]!=s[j]){
			j=p[j-1];
		}
		if(s[i]==s[j]){
			j++;
		}
		p[i]=j;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s[2];
	int n;
	cin>>n;
	FOR(i,0,2){
		s[i]=string(M,'0');
		FOR(j,0,n){
			int a;
			cin>>a;
			s[i][a]='1';
		}
	}
	string t=s[0]+'2'+s[1]+s[1];
	pi(t);
	if(*max_element(p,p+SZ(t))<M){
		cout<<"NO\n";
	}
	else cout<<"YES\n";
	return 0;
}


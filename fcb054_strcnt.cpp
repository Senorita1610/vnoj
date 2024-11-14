#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
const int M=30;
string s,t;
int cntT[M],cnt[N][M],n,m,result;
bool check(int l,int r){
	for(int i=1;i<=26;i++){
		if(cnt[r][i]-cnt[l-1][i]!=cntT[i]) return false;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>t;
	n=s.size();
	m=t.size();
	s=" "+s;
	t=" "+t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++) cnt[i][j]=cnt[i-1][j];
		cnt[i][s[i]-'a'+1]++;
	}
	for(int i=1;i<=m;i++) cntT[t[i]-'a'+1]++;
	for(int i=1;i<=n-m+1;i++) result+=check(i,i+m-1);
	cout<<result;
}


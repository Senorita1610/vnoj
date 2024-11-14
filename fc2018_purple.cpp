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
const int LOG=18;
const int MAX=1<<LOG;
vector<string>s;
vector<int>idxes;
int lg[MAX];
int lcp[LOG][MAX];
int query(int l,int r){
	if(l==r) return SZ(s[idxes[l]]);
	r--;
	int i=lg[r-l+1];
	return min(lcp[i][l],lcp[i][r-(1<<i)+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	lg[1]=0;
	FOR(i,2,MAX){
		lg[i]=lg[i-1];
		if((1<<(lg[i]+1))<=i) lg[i]++;
	}
	int n,q;
	cin>>n>>q;
	s.resize(n);
	for(auto& si:s) cin>>si;
	idxes.resize(n);
	iota(ALL(idxes),0);
	sort(ALL(idxes),[&](int i,int j){
		return s[i]<s[j];
	});
	vector<int>pos(n);
	FOR(i,0,n) pos[idxes[i]]=i;
	FOR(i,0,n-1){
		while(lcp[0][i]<min(SZ(s[idxes[i]]),SZ(s[idxes[i+1]]))&&s[idxes[i]][lcp[0][i]]==s[idxes[i+1]][lcp[0][i]]) lcp[0][i]++;	
	}
	FOR(j,1,LOG){
		FOR(i,0,n+1-(1<<j)){
			lcp[j][i]=min(lcp[j-1][i],lcp[j-1][i+(1<<(j-1))]);
		}
	}
	while(q--){
		int k,l;
		cin>>k>>l;
		vector<int>vec(k);
		for(int& y:vec){
			int x;
			cin>>x;
			x--;
			y=pos[x];
		}
		sort(ALL(vec));
		int ans=0;
		FOR(i,0,k-l+1){
			ans+=query(vec[i],vec[i+l-1]);
			int mx=0;
			if(i>0){
				mx=max(mx,query(vec[i-1],vec[i+l-1]));
			}
			if(i+l<k){
				mx=max(mx,query(vec[i],vec[i+l]));
			}
			ans-=mx;
		}
		cout<<ans<<endl;
	}
	return 0;
}


#include<bits/stdc++.h>
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y))<eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod=1e9+7;
long double PI=acosl(-1);
const ll infl=1e17;
const int nmax=1e6+10;
const int MAXLG=log2(nmax)+1;
int bit[1005][30000+10];
int m,n;
int cnt[nmax];
void update(int idx,int L,int R,int v){
	bit[idx][L]+=v,bit[idx][R+1]-=v;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	int k;
	cin>>k;
	for(int p=0;p<k;p++){
		int i,j,r,b;
		cin>>i>>j>>r>>b;
		for(int i1=max(1,i-r);i1<=min(n,i+r);i1++){
			int d=sqrtl(1LL*r*r-(i-i1)*(i-i1));
			int j1=max(1,j-d);
			int j2=min(m,j+d);
			update(i1,j1,j2,b);
		}
	}
	for(int i=1;i<=n;i++){
		int cur=0;
		for(int j=1;j<=m;j++){
			cur+=bit[i][j];
			cnt[cur]++;
		}
	}
	for(int i=nmax-1;i>=1;i--){
		if(cnt[i]){
			cout<<i<<"\n"<<cnt[i]<<"\n";
			exit(0);
		}
	}
}


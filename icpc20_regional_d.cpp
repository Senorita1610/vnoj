#include<bits/stdc++.h>
#define DBG(a) cerr<<"line "<<__LINE__<<" : "<<#a<<" --> "<<(a)<<endl
#define EPS 1e-8
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod = 998244353;
long double pi = acosl(-1);
const ll infl = 1e18+100;
const int mmax=40;
const int nmax=62;
bool posible[mmax][nmax][nmax];
bool dp[mmax][nmax];
int dpback[mmax][nmax];
int cnt[mmax][nmax];
int tmp[nmax];
int lpos[mmax],rpos[mmax];
bool work(int idx,int S,int T){
	if(cnt[idx][S]==0 or cnt[idx][T]==0) return false;
	int L=lpos[idx],R=rpos[idx];
	if(S<L or R<S or T<L or R<T) return false;
	for(int i=L;i<=R;i++) tmp[i]=cnt[idx][i];
	bool ret=true;
	if(S<=T){
		for(int i=L;i<S and ret;i++){
			if(tmp[i]){
				if(tmp[i+1]>=tmp[i]+1) tmp[i+1]-=tmp[i];
				else ret=false;
			}
		}
		for(int i=S;i<T and ret;i++){
			if(tmp[i]>=1){
				tmp[i+1]-=tmp[i]-1;
			}
			else ret=false;
		}
		for(int i=R;i>T and ret;i--){
			if(tmp[i]){
				if(tmp[i-1]>=tmp[i]+1){
					tmp[i-1]-=tmp[i];
				}
				else ret=false;
			}
		}
	}
	else{
		for(int i=R;i>S and ret;i--){
			if(tmp[i]){
				if(tmp[i-1]>=tmp[i]+1){
					tmp[i-1]-=tmp[i];
				}
				else ret=false;
			}
		}
		for(int i=S;i>T and ret;i--){
			if(tmp[i]>=1){
				tmp[i-1]-=tmp[i]-1;
			}
			else ret=false;
		}
		for(int i=L;i<T and ret;i++){
			if(tmp[i]){
				if(tmp[i+1]>=tmp[i]+1){
					tmp[i+1]-=tmp[i];
				}
				else ret=false;
			}
		}
	}
	if(ret) ret=(tmp[T]==1);
	for(int i=L;i<=R;i++) tmp[i]=0;
	return ret;
}
ll getnum(int p3,int p2){
	ll ret=1;
	while(p2--) ret*=2;
	while(p3--) ret*=3;
	return ret;
}
vector<ll>reconstruct(int idx,int S,int T){
	int L=lpos[idx],R=rpos[idx];
	for(int i=L;i<=R;i++) tmp[i]=cnt[idx][i];
	vector<ll>ret;
	if(S<=T){
		for(int i=S;i>L;i--){
			tmp[i]--;
			ret.push_back(getnum(idx,i));
		}
		for(int i=L;i<T;i++){
			while(tmp[i]>1){
				ret.push_back(getnum(idx,i));
				ret.push_back(getnum(idx,i+1)),tmp[i+1]--;
				tmp[i]--;
			}
			ret.push_back(getnum(idx,i));
		}
		for(int i=T;i<R;i++){
			tmp[i]--;
			ret.push_back(getnum(idx,i));
		}
		for(int i=R;i>T;i--){
			while(tmp[i]>1){
				ret.push_back(getnum(idx,i));
				ret.push_back(getnum(idx,i-1)),tmp[i-1]--;
				tmp[i]--;
			}
			ret.push_back(getnum(idx,i));
		}
		ret.push_back(getnum(idx,T));
	}
	else{
		for(int i=S;i<R;i++){
			tmp[i]--;
			ret.push_back(getnum(idx,i));
		}
		for(int i=R;i>T;i--){
			while(tmp[i]>1){
				ret.push_back(getnum(idx,i));
				ret.push_back(getnum(idx,i-1)),tmp[i-1]--;
				tmp[i]--;
			}
			ret.push_back(getnum(idx,i));
		}
		for(int i=T;i>L;i--){
			tmp[i]--;
			ret.push_back(getnum(idx,i));
		}
		for(int i=L;i<T;i++){
			while(tmp[i]>1){
				ret.push_back(getnum(idx,i));
				ret.push_back(getnum(idx,i+1)), tmp[i+1]--;
				tmp[i]--;
			}
			ret.push_back(getnum(idx,i));
		}
		ret.push_back(getnum(idx,T));
	}
	for(int i=L;i<=R;i++) tmp[i]=0;
	return ret;
}
void solv(int n){
	int borob=0,boroa=0;
	bool badinput=false;
	for(int i=0;i<n;i++){
		int B=0,A=0;
		ll x;
		cin>>x;
		while(x%3==0) x/=3,B++;
		while(x%2==0) x/=2,A++;
		if(x!=1) badinput=true;
		cnt[B][A]++;
		borob=max(borob,B);
		boroa=max(boroa,A);
	}
	for(int mm=0;mm<=borob;mm++){
		int L=nmax-1,R=-1;
		for(int i=0;i<=boroa;i++) if(cnt[mm][i]){
			L=min(L,i),R=max(R,i);
		}
		lpos[mm]=L,rpos[mm]=R;
	}
	for(int i=0;i<=borob;i++){
		for(int L=lpos[i];L<=rpos[i];L++) for(int R=lpos[i];R<=rpos[i];R++){
			posible[i][L][R]=work(i,L,R);
		}
	}
	for(int i=0;i<=boroa;i++) dp[0][i]=posible[0][0][i];
	for(int i=1;i<=borob;i++){
		for(int j=0;j<=boroa;j++){
			dp[i][j]=false;
			for(int k=0;k<=boroa;k++){
				if(dp[i-1][k] and posible[i][k][j]){
					dp[i][j]=true;
					dpback[i][j]=k;
					break;
				}
			}
		}
	}
	if(badinput) cout<<"NO\n";
	else{
		bool found=false;
		for(int j=0;j<=boroa;j++) if(dp[borob][j]){
			cout<<"YES\n";
			vector<ll>ans;
			for(int pow3=borob;pow3>=0;pow3--){
				vector<ll>tmp=reconstruct(pow3,dpback[pow3][j],j);
				reverse(tmp.begin(),tmp.end());
				for(ll x : tmp) ans.push_back(x);
				j=dpback[pow3][j];
			}
			reverse(ans.begin(),ans.end());
			for(auto z:ans) cout<<z<<" ";
			cout<<"\n";
			for(int i=1;i<ans.size();i++){
				assert(ans[i]==ans[i-1]*2 or ans[i]==ans[i-1]*3 or ans[i]*2==ans[i-1]);
			}
			found=true;
			break;
		}
		if(!found) cout<<"NO\n";
	}
	for(int i=0;i<=borob;i++){
		for(int j=0;j<=boroa;j++) cnt[i][j]=0;
	}
	for(int i=0;i<=borob;i++){
		for(int L=lpos[i];L<=rpos[i];L++) for(int R=lpos[i];R<=rpos[i];R++){
			posible[i][L][R]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		solv(n);
	}
}


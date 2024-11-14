#include<bits/stdc++.h>
using namespace std;
using  ll = long long;
struct T{
	char awal = '?';
	char akhir = '?';
	int cnt[26]={0};
	int len=0;
};
vector<T>a;
void create(string s){
	T x;
	x.awal=s[0];
	x.akhir=s.back();
	for(char c:s){
		x.cnt[c-'a']++;
	}
	x.len=s.size();
	a.push_back(x);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;cin>>s;
	create(s);
	int q;
	cin>>q;
	const int MOD=1e9+7;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int i;
			char c;
			cin>>i>>c;
			T ti=a[i];
			(ti.cnt[c-'a']+=1)%=MOD;
			ti.akhir=c;
			(ti.len+=1)%=MOD;
			a.push_back(ti);
		}
		else if(op==2){
			int i;
			char c;
			cin>>i>>c;
			T ti=a[i];
			(ti.cnt[c-'a']+=1)%=MOD;
			ti.awal=c;
			(ti.len+=1)%=MOD;
			a.push_back(ti);
		}
		else if(op==3){
			int i,j;
			cin>>i>>j;
			T tx;
			for(int k=0;k<26;k++){
				tx.cnt[k]=(a[i].cnt[k]+a[j].cnt[k])%MOD;
			}
			tx.awal=a[i].awal;
			tx.akhir=a[j].akhir;
			tx.len=(a[i].len+a[j].len)%MOD;
			a.push_back(tx);
		}
		else if(op==4){
			int i;
			cin>>i;
			T ti=a[i];
			swap(ti.awal,ti.akhir);
			a.push_back(ti);
		}
		else{
			int i,j;
			cin>>i>>j;
			T ti=a[i],tj=a[j];
			(ti.cnt[ti.awal-'a']+=MOD-1)%=MOD;
			(tj.cnt[tj.akhir-'a']+=MOD-1)%=MOD;
			ll ans=(ll)ti.len*tj.len%MOD;
			for(int k=0;k<26;k++){
				ans+=(MOD-(ll)ti.cnt[k]*tj.cnt[k]%MOD);
				ans%=MOD;
			}
			cout<<ans<<endl;
			a.push_back(a.back());
		}
	}
	return 0;
}


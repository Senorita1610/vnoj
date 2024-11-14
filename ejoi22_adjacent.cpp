#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
const int N=2e5+10;
int n,a[N],cnto[N],cnte[N],odd[N],even[N];
map<int,int>m[N];
bool cmp(int x,int y){
	return cnto[x]>cnto[y];
}
bool cmp2(int x,int y){
	return cnte[x]>cnte[y];
}
void solve(){
	cin>>n;
	for(int i=1;i<=n+1;i++)m[i].clear(),odd[i]=even[i]=i,cnto[i]=cnte[i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i%2) cnto[a[i]]++;
		else cnte[a[i]]++;
	}
	sort(odd+1,odd+1+n,cmp);
	sort(even+1,even+1+n,cmp2);
	for(int i=1;i<=n;i++){
		if(i%2==1) m[a[i]][a[i+1]]++;
		else m[a[i+1]][a[i]]++;
		if(a[i]==a[i+2]) i=i+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(odd[i]==even[j]) continue;
			ans=max(ans,cnto[odd[i]]+cnte[even[j]]-m[even[j]][odd[i]]);
			if(m[even[j]][odd[i]]==0) break;
		}
	}
	printf("%d\n",n-ans);
}
int main(){
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
int ar[100003];
int a[100003];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&ar[i]);
		int x=ar[i]%n;
		int p=ar[i]-n;
		int kop=ar[i-1];
		int ma=max(kop,p);
		int lp=(ma+1)%n;
		if(lp<=x){
			a[lp]+=1;
			a[x+1]-=1;
		}
		else{
			a[lp]++;
			a[0]++;
			a[x+1]--;
		}
	}
	int mi=m;
	for(int i=0;i<n;i++){
		if(i>0) a[i]+=a[i-1];
		mi=min(mi,a[i]);
	}
	vector<int>v;
	for(int i=0;i<n;i++){
		if(mi==a[i]){
			if(i==0) v.push_back(n);
			else v.push_back(i);
		}
	}
	printf("%d\n",mi);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		if(i>0) printf(" ");
		printf("%d",v[i]);
	}
	printf("\n");
	return 0;
}


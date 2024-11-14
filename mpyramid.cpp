#include<bits/stdc++.h>
using namespace std;
const int N=1e3+4;
const int inf=1e9+4;
struct Min_Queue{
	int min_=inf;
	stack<int>d1,d2;
	void clear(){
		min_=inf;
		while(d1.size()) d1.pop();
		while(d2.size()) d2.pop();
	}
	void push(int x){
		d1.push(x);
		min_=min(min_,x);
	}
	void pop(){
		if(d2.empty()){
			while(d1.size()){
				if(d2.empty()){
					d2.push(d1.top());
				}
				else{
					d2.push(min(d1.top(),d2.top()));
				}
				d1.pop();
			}
			min_=inf;
		}
		d2.pop();
	}
	int _min(){
		if(d2.empty()) return min_;
		return min(min_,d2.top());
	}
}d;
int n,m,n1,m1,n2,m2;
int pr[N][N],a[N][N];
int Sum(int i1,int j1,int i2,int j2){
	return pr[i2][j2]-pr[i2][j1-1]-pr[i1-1][j2]+pr[i1-1][j1-1];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n>>m1>>n1>>m2>>n2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>pr[i][j];
			pr[i][j]+=pr[i-1][j]+pr[i][j-1]-pr[i-1][j-1];
		}
	}
	for(int j=1;j<=m-m2+1;j++){
		d.clear();
		for(int i=n-n2+1;i>0;i--){
			d.push(Sum(i,j,i+n2-1,j+m2-1));
			if(i<=n-n1+2) d.pop();
			a[i][j]=d._min();
		}
	}
	int ans=0,ans_i,ans_j;
	for(int i=1;i<=n-n1+3;i++){
		d.clear();
		for(int j=m-m2+1;j>0;j--){
			d.push(a[i][j]);
			if(j<=m-m1+2) d.pop();
			if(2<=i&&i<=n-n1+2&&2<=j&&j<=m-m1+2){
				int aux=Sum(i-1,j-1,i+n1-2,j+m1-2)-d._min();
				if(aux>ans){
					ans=aux,ans_i=i-1,ans_j=j-1;
				}
			}
		}
	}
	int val=Sum(ans_i,ans_j,ans_i+n1-1,ans_j+m1-1)-ans;
	for(int i=ans_i+1;i+n2<=ans_i+n1-1;i++){
		for(int j=ans_j+1;j+m2<=ans_j+m1-1;j++){
			if(Sum(i,j,i+n2-1,j+m2-1)==val){
				cout<<ans_j<<" "<<ans_i<<endl;
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;	
}


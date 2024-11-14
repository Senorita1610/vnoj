#include<bits/stdc++.h>
using namespace std;
using ld = long double;
const ld EPS = 1e-11;
const int N = 100;
ld A[N];
int n,k,x;
void pour(vector<int>nisi,ld target){
	cout<<"POUR "<<nisi.size();
	for(int j=0;j<nisi.size();j++){
		cout<<" "<<nisi[j];
		cout<<fixed<<setprecision(10)<<" "<<target-A[nisi[j]];
		A[nisi[j]]=target;
	}
	cout<<endl;
	int pos;
	cin>>pos;
	for(int j=pos;j<pos+k;j++) A[j]=0.0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k>>x;
	if(n==k){
		cout<<"FINAL 1 1 "<<x<<endl;
	}
	else{
		int mx=(n+k-1)/k;
		for(int i=1;i<2000-mx+2;i++){
			ld target=0;
			vector<int>nisi;
			for(int j=0;j<mx;j++) target+=A[j*k+1],nisi.push_back(j*k+1);
			target+=x;
			target/=mx;
			pour(nisi,target);
		}
		for(int i=0;i<mx-2;i++){
			ld target=0;
			ld mv=0;
			for(int j=0;j<mx;j++){
				mv=max(mv,A[j*k+1]);
			}
			vector<int>nisi;
			for(int j=0;j<mx;j++){
				if(nisi.size()==mx-1-i) break;
				if(abs(mv-A[j*k+1])>EPS) continue;
				target+=A[j*k+1];
				nisi.push_back(j*k+1);
			}
			assert(nisi.size()==mx-1-i);
			target+=x;
			target/=(mx-1-i);
			pour(nisi,target);
		}
		int pos=1;
		for(int i=1;i<=n;i++) if(A[i]>A[pos]) pos=i;
		cout<<"FINAL 1 "<<pos<<" "<<x<<endl;
	}
}


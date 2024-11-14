#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=23;
const int M=450;
const ld SCALE=1e3;
bool gaussianElimination(int n,ld sys[M][M],ld *solution){
	int i,j,k,r;
	for(i=0;i<n;i++){
		r=i;
		for(j=i+1;j<n;j++){
			if(fabs(sys[j][i])>fabs(sys[r][i])) r=j;
		}
		for(j=0;j<=n and r!=i ;++j) swap(sys[i][j],sys[r][j]);
		for(k=i+1;k<n;k++){
			ld x=sys[k][i]/sys[i][i];
			for(j=i;j<=n;j++) sys[k][j]-=x*sys[i][j];
		}
	}
	for(i=n-1;i>=0;i--){
		for(j=i+1;j<n;j++){
			sys[i][n]-=sys[j][n]*sys[i][j];
		}
		sys[i][n]/=sys[i][i],solution[i]=sys[i][n];
	}
	return 1;
}
int get(string &s, int prv, char c){
	string cur = s.substr(0,prv)+c;
	for(int i=prv+1;i;i--){
		if(cur.substr(prv+1-i,i)==s.substr(0,i)){
			return i;
		}
	}
	return 0;
}
string s,t;
int ptr,id[N][N];
ld p,sys[M][M],res[M];
int main(){
	cin>>s>>t>>p;
	p*=SCALE;
	int n=s.size(),m=t.size();
	if(n>=m and s.substr(n-m,m)==t){
		cout<<"0\n";
		return 0;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			id[i][j]=ptr++;
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			sys[id[i][j]][id[i][j]]+=SCALE;
			if(j==m){
				sys[id[i][j]][ptr]+=0;
				continue;
			}
			if(i==n){
				sys[id[i][j]][ptr]+=SCALE;
				continue;
			}
			sys[id[i][j]][id[get(s,i,'H')][get(t,j,'H')]]-=p;
			sys[id[i][j]][id[get(s,i,'T')][get(t,j,'T')]]-=SCALE-p;
		}
	}
	assert(gaussianElimination(ptr,sys,res));
	printf("%0.12f\n",(double)res[0]);
	return 0;
}


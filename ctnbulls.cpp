#include<bits/stdc++.h>
using namespace std;
int fn[100001],fg[100001],n,k;
int main(){
	cin>>n>>k;
	fn[1]=1;
	fg[1]=1;
	for(int i=2;i<=n;i++){
		fn[i]=(fn[i-1]+fg[i-1])%2111992;
		if(i>k+1){
			fg[i]=(fg[i-k-1]+fn[i-k-1])%2111992;
		}
		else{
			fg[i]=1;	
		}
	}
	cout<<(fg[n]+fn[n])%2111992<<endl;
	return 0;
}


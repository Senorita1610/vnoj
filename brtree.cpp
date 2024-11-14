#include<iostream>
using namespace std;
int main(){
	int N,K;
	while(cin>>N>>K,N){
		if(K==0){
			cout<<min(N-1,1234567891)<<endl;
			continue;
		}
		long long res=0,nn=1,s[100000],t[100000];s[1]=K!=0;t[1]=1;
		for(int i=2;i<=N&&res<=1234567890;i++){
			res+=nn;
			nn+=s[i-1];
			if(i<=K) s[i]=(1LL<<(i-1)),t[i]=s[i]/2;
			else s[i]=2*s[i-1]-t[i-K],t[i]=s[i-1];
		}
		cout<<res<<endl;
	}
	return 0;
}


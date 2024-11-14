#include<array>
#include<functional>
#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int A,B,L;
	cin>>A>>B>>L;
	auto cal = [&](int y) -> int {
		if(y==0) return 1;
		vector<int>prime;
		for(int i=2;i*i<=y;i++){
			if(y%i==0){
				prime.push_back(i);
				while(y%i==0){
					y/=i;
				}
			}
		}
		if(y!=1){
			prime.push_back(y);
		}
		int res=0;
		for(int mask=1;mask<(1<<(int)prime.size());mask++){
			int num=1;
			int cnt=0;
			for(int i=0;i<(int)prime.size();i++){
				if((mask>>i)&1){
					num*=prime[i];
					cnt++;
				}
			}
			if(cnt%2==0){
				res-=L/num;
			}else{
				res+=L/num;
			}
		}
		return L-res;
	};
	long long s=0,is=0;
	for(int y=0;y<=A+B;y++){
		int cy=A+B-y;
		int g=gcd(y,cy);
		int l=y*cy/g;
		int coprime_with_both=cal(l);
		s+=coprime_with_both;
		is+=L-cal(y)-cal(cy)+coprime_with_both;
	}	
	cout<<is<<endl;
	cout<<1LL*(A+B+1)*L-is-s<<endl;
	cout<<s<<endl;
}


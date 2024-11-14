#include<iostream>
long long n,f[512]={1,0};
int main(){
	std::cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			f[j]=f[j]+f[j-i];
		}
	}
	std::cout<<f[n]-1;
}


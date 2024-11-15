#include<iostream>
using namespace std;
int n;
double a[3000],x;
int main(){
	cin>>n;
	a[0]=1;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int o=min(i,(n+1)/2);o>0;o--){
			a[o]=a[o-1]*x+a[o]*(1-x);
		}
	}
	printf("%.10lf",a[(n+1)/2]);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long i,k,x;
int main(){
	while(cin>>x){
		k=0;
		i=2;
		while(i*i<=x){
			while(x%i!=0&&i*i<=x) i++;
			while(x%i==0&&i*i<=x){
				k++;
				x=x/i;
			} 
		}
		cout<<k+1<<endl;
	}
	return 0;
}


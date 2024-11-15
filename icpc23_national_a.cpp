#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(c==0) puts("NO CURVE");
		else{
			if(c>0) puts("CURVE UP");
			else puts("CURVE DOWN");
		}
	}
	return 0;
}


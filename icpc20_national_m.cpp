#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		long long x=abs(a-c),y=abs(d-b);
		if(x>y) swap(x,y);
		y-=x;
		printf("%lld\n",x*2+y+(y/2)*2);
	}
}


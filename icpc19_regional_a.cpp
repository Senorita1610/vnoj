#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
lll t,r,c,m=1000000007;
lll bgm(lll x,lll y,lll z=1){
	for(;y;y&1?z=z*x%m:0,x=x*x%m,y>>=1);
	return z;
}
int main(){
	for(scanf("%lld",&t);t--;scanf("%lld%lld",&r,&c),printf("%lld\n",bgm(2,r*c)*bgm(3,r+c)%m));
	exit(0);
}


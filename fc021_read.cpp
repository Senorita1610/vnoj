#include<cstdio>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	while(k--){
		int s,t,r;
		scanf("%d%d%d",&s,&t,&r);
		printf("%d\n",(n+s-1)/s+((n+s*t-1)/(s*t)-1)*r);
	}
	return 0;
}


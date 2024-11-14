#include<cstdio>
#include<algorithm>
using namespace std;
struct pig{
	long long data;
	int id;
}w[1005];
struct price{
	long long data;
	int id;
}p[1005];
bool cmp1(pig a,pig b){
	return a.data>b.data;
}
bool cmp2(price a,price b){
	return a.data>b.data;
}
int a[1005];
long long d[1005];
int main(int argc,char* argv[]){
	int n;
	long long t;
	int i;
	while(scanf("%d %lld",&n,&t)!=EOF){
		for(i=0;i<n;i++){
			scanf("%lld",&w[i].data);
			w[i].id=i+1;
		}
		for(i=0;i<n;i++){
			scanf("%lld",&d[i]);
		}
		for(i=0;i<n;i++){
			scanf("%lld",&p[i].data);
			p[i].data=p[i].data-d[i]*t;
			p[i].id=i+1;
		}
		sort(p,p+n,cmp2);
		sort(w,w+n,cmp1);
		for(i=0;i<n;i++){
			a[p[i].id]=w[i].id;
		}
		for(i=1;i<n;i++){
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n]);
	}
	return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
const int nn=505;
int n,deg[nn],list[nn];
int cmp(int a,int b){
	return deg[a]<deg[b];
}
int check(int p){
	static char str[5];
	if(p==1){
		printf("? 2 %d %d\n",list[2],list[3]);
		fflush(stdout);
		scanf("%s",str);
		return str[0]=='N';
	}
	printf("? %d ",p);
	for(int i=1;i<=p;i++){
		printf("%d ",list[i]); puts("");
	}
	fflush(stdout);
	scanf("%s",str);
	return str[0]=='Y';
}
int main(){
	scanf("%d",&n);
	for(int i=1,p,q;i<n;i++){
		scanf("%d%d",&p,&q);
		deg[p]++;deg[q]++;
		list[i]=i;
	}
	list[n]=n;
	std::sort(list+1,list+n+1,cmp);
	int l=1,r=n,mid;
	while(l<r){
		if(check(mid=l+r>>1)) r=mid;
		else l=mid+1;
	}
	printf("! %d\n",list[l]);fflush(stdout);
}


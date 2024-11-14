#include<cstdio>
int f(int p,int q){
	if(p==q) return 1;
	else if(p<q) return 2*f(p,q-p);
	else return 2*f(p-q,q)+1;
}
int main(){
	int p,q;
	scanf("%d/%d",&p,&q);
	printf("%d\n",f(p,q));
	return 0;
}


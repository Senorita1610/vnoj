#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
u N[25][3333],V[111111],vi,P[25],D[25];
u G(u x,u y){
	++vi;
	u i,j;
	i=x;
	j=y;
	while(i--) V[N[i][j]]=vi;i=x;j=y;
	while(j--) V[N[i][j]]=vi;i=x;j=y;
	while(i--&&j--) V[N[i][j]]=vi;
	for(i=-1;V[++i]==vi;);
	return i;
}
llu F(u x,llu y){
	llu d;
	if(y<2000) return N[x][y];
	d=D[x]*(llu)((y-2000)/P[x]);
	y=(y-2000)%P[x]+2000;
	return N[x][y]+d;
}
int main(){
	u i,j,k,d,t,x,y,q,a;
	llu b,h;
	for(i=-1;++i<25;) for(j=-1;++j<3333;) N[i][j]=G(i,j);
	for(i=-1;++i<25;){
		for(j=0;++j;){
			d=N[i][j+2000]-N[i][2000];
			for(k=j+2000;++k<3333;) if(N[i][k]-N[i][k-j]!=d) goto tjan;
			break;
			tjan:;
		}
		D[i]=d;
		P[i]=j;
	}
	for(scanf("%u",&t);t--;){
		scanf("%u%u%u",&x,&y,&q);
		--x;
		--y;
		for(i=-1,h=0;++i<q;){
			scanf("%u%llu",&a,&b);
			--a;
			--b;
			h^=F(a,b);
		}
		printf(h?"YES\n":"NO\n");
	}
	return 0;
}


#include<bits/stdc++.h>
#define re register
#define Maxm 100005
using namespace std;

int C,M,Ans=Maxm,tot;

inline int read(){
	re int ret=0;
	re char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
	return ret;
}

struct dr{
	int L,R;
	int Nxt[20];
} t1[Maxm],t[Maxm<<1];

inline bool cmp(dr x,dr y){
	return x.L<y.L;
}

int main(){
	C=read();
	M=read();
	for(re int i=1;i<=M;i++){
		t1[i].L=read();
		t1[i].R=t1[i].L+read();
	}
	sort(t1+1,t1+1+M,cmp);
	for(re int i=1;i<=M;i++){ 
		if(t1[i].R>t[tot].R){
			t[++tot]=t1[i];
		}
	}
	M=tot;
	for(re int i=1;i<=M;i++){
		t[i+M].L=t[i].L+C;
		t[i+M].R=t[i].R+C;
	}
	re int tmp=1;
	for(re int i=1;i<=M<<1;i++){
		t[i].Nxt[0]=t[i-1].Nxt[0];
		for(;tmp<=M<<1&&t[tmp].L<=t[i].R;tmp++){ 
			if(t[tmp].R>t[t[i].Nxt[0]].R) t[i].Nxt[0]=tmp;
		}
	}
	for(re int i=M<<1;i;i--){ 
		for(re int j=1;j<=18&&t[t[i].Nxt[j-1]].Nxt[j-1];j++){
			t[i].Nxt[j]=t[t[i].Nxt[j-1]].Nxt[j-1];
		}
	}
	for(re int i=1,sum,now;i<=M;i++){
		sum=1; now=i;
		for(re int j=18;j>=0;j--){ 
			if(t[now].Nxt[j]&&t[t[now].Nxt[j]].R-t[i].L<C){
				now=t[now].Nxt[j];
				sum+=1<<j;
			}
		}
		if(t[now].Nxt[0]&&t[now].R-t[i].L<C){
			sum++; now=t[now].Nxt[0];
		}
		if(t[now].R-t[i].L>=C) Ans=min(Ans,sum);
	}
	printf("%d",Ans);
	return 0;
}


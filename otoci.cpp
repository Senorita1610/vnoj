#include<bits/stdc++.h>
using namespace std;
struct node{
	int son[2],fa,sum,tag;
}g[1000000];
int a[1000000],n,m,sta[1000000];
inline int read(){
	register int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
inline void pushup(int rt){
	g[rt].sum=g[g[rt].son[0]].sum+g[g[rt].son[1]].sum+a[rt];
}
inline void reverse(int rt){
	swap(g[rt].son[1],g[rt].son[0]);
	g[rt].tag^=1;
}
inline void pushdown(int rt){
	if (g[rt].tag){
		if (g[rt].son[0]) reverse(g[rt].son[0]);
		if (g[rt].son[1]) reverse(g[rt].son[1]);
		g[rt].tag=0;
	}
}
inline bool isrt(int rt){
	return (g[g[rt].fa].son[1]!=rt&&g[g[rt].fa].son[0]!=rt);
}
inline bool wtson(int rt){
	if (g[g[rt].fa].son[0]==rt) return 0; return 1;
}
inline void connect(int rt,int fa,int wht){
	if (rt) g[rt].fa=fa;g[fa].son[wht]=rt;
}
inline void rotate(int rt){
	register int fa=g[rt].fa,fafa=g[fa].fa,wht=wtson(rt),whtfa=wtson(fa),son=g[rt].son[1^wht];
	connect(son,fa,wht);g[rt].fa=fafa;
	if (fafa&&!isrt(fa)) g[fafa].son[whtfa]=rt;
	connect(fa,rt,1^wht);pushup(fa);
}
inline void splay(int rt){
	register int top=1;sta[top]=rt;
	for (register int i=rt;!isrt(i);i=g[i].fa) sta[++top]=g[i].fa;
	for (register int i=top;i>=1;i--) pushdown(sta[i]);
	while (!isrt(rt)){
		register int fa=g[rt].fa;
		if (isrt(fa)) rotate(rt);
		else if (wtson(fa)==wtson(rt)) rotate(fa),rotate(rt);
		else rotate(rt),rotate(rt);
	}	
	pushup(rt);
}
inline void access(int rt){
	for (register int fa=0;rt;rt=g[fa=rt].fa){
		splay(rt);g[rt].son[1]=fa;pushup(rt);
	}
}
inline void makert(int rt){
	access(rt);splay(rt);reverse(rt);
}
inline int findrt(int rt){
	access(rt);splay(rt);
	while (g[rt].son[0]){
		pushdown(rt);rt=g[rt].son[0];
	}
	return rt;
}
inline void split(int x,int y){
	makert(x);access(y);splay(y);
}
inline void link(int x,int y){
	makert(x);
	if (findrt(x)!=findrt(y)) g[x].fa=y;
}
inline bool iscnt(int x,int y){
	return (findrt(x)==findrt(y));
}
inline int query(int x,int y){
    split(x,y);return g[y].sum;
}
inline void change(int rt,int w){
    splay(rt);a[rt]=w;pushup(rt);
}
int main(){
	n=read();
	for (register int i=1;i<=n;i++){
		a[i]=read();
	}
	m=read();
	while (m--){
		char czx[112];register int x,y;
		scanf("%s",czx);x=read();y=read();
		switch (czx[0]){
			case 'b':{
				bool xj=iscnt(x,y);
				if (xj) printf("no\n");
				else{printf("yes\n");link(x,y);}
				break;
			}
			case 'p':{change(x,y);break;}
			case 'e':{
				bool xj=iscnt(x,y);
				if (!xj) printf("impossible\n");
				else{printf("%d\n",query(x,y));}break;
			}
		}
	}
}


#include<bits/stdc++.h>
#include<tr1/unordered_map>
#pragma GCC optimize(2)
#define ls (o<<1)
#define rs (o<<1|1)
#define mid (ll+lr>>1)
using namespace std;
const int N=401010;
int n,cl,num[N],cnt;
int sum[N<<2|1],mx[N<<2|1],fl[N<<2|1],l,r,k;
bool book[N<<2|1];
tr1::unordered_map<int,int> mp;
struct aa
{
	int a,b,d;
}que[N];
int read()
{
	int res=0,fl=0;
	char a=getchar();
	while(a<'0'||a>'9') {if(a=='-') fl=1;a=getchar();}
	while(a>='0'&&a<='9') res=res*10+a-'0',a=getchar();
	return fl? -res:res;
}
void pushr(int o,int ll,int lr,int lk) {sum[o]=(num[lr]-num[ll-1])*lk,mx[o]=max(0,sum[o]),fl[o]=lk,book[o]=1;}
void push_down(int o,int ll,int lr) {if(book[o]) pushr(ls,ll,mid,fl[o]),pushr(rs,mid+1,lr,fl[o]),book[o]=0;}
void update(int o,int ll,int lr)
{
	if(l<=ll&&lr<=r) return pushr(o,ll,lr,k);
	push_down(o,ll,lr);
	if(l<=mid) update(ls,ll,mid);
	if(r>mid) update(rs,mid+1,lr);
	sum[o]=sum[ls]+sum[rs],mx[o]=max(mx[ls],mx[rs]+sum[ls]); 
}
int query(int o,int ll,int lr,int lk)
{
	if(o==1&&lk>=mx[o]) return n; 
	if(ll==lr) return sum[o]? num[ll-1]+lk/(sum[o]/(num[ll]-num[ll-1])):num[ll]; 
	push_down(o,ll,lr);
	if(mx[ls]>lk) return query(ls,ll,mid,lk);
	return query(rs,mid+1,lr,lk-sum[ls]); 
}
void add(int lx) {num[++cl]=lx,num[++cl]=lx-1;}
int main()
{
	int i,j,li,lj;
	n=read();
	while(1)
	{
		char a=getchar();
		while(a<'A'||a>'Z') a=getchar();
		if(a=='E') break;
		if(a=='I') add(que[++cnt].a=read()),add(que[cnt].b=read()),que[cnt].d=read();
		if(a=='Q') que[++cnt].d=read(); 
	}
	num[++cl]=n,sort(num+1,num+cl+1),cl=unique(num+1,num+cl+1)-num-1; 
	if(num[1]==0) {for(i=1;i<cl;i++) num[i]=num[i+1];cl--;}
	for(i=1;i<=cl;i++) mp[num[i]]=i; 
	for(i=1;i<=cnt;i++)
		if(que[i].a) l=mp[que[i].a],r=mp[que[i].b],k=que[i].d,update(1,1,cl);
		else cout<<query(1,1,cl,que[i].d)<<'\n';
	return 0;
}


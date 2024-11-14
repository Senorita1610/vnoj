#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
char s[MAXN];
int c[MAXN*5][30],qu[MAXN];
int q,len;
struct node
{
	int l,r;
}t[MAXN];
int lowbit(int x){return x & -x;}
void add(int x,int y,int k)
{
	for(int i=x;i<=len;i+=lowbit(i))	c[i][y]+=k;
}
int query(int x,int y)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))	ans+=c[i][y];
	return ans;
}
bool check() 
{
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=26;j++)
		{
			if(query(t[i].r,j)-query(t[i].l-1,j)>=2)	return 0; 
		}
	}
	return 1;
}
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)	scanf("%d %d",&t[i].l,&t[i].r);
	for(int i=1;i<=len;i++)	add(i,s[i]-'a'+1,1); 
	if(check())
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=len;i++)	scanf("%d",&qu[i]);
	for(int i=1;i<=len;i++)
	{
		add(qu[i],s[qu[i]]-'a'+1,-1);
		if(check())
		{
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}


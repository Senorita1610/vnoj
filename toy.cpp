#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
const int inf=1000000000; 
int d,n1,n2,c1,c2,tc,l,r,t[maxn];
struct code
{int Day,toys;};
deque<code> n,o,m;
void add(int day,int toy)
{
	code now;
	now.Day=day,now.toys=toy;
	n.push_back(now);
}
void newch (int x)
{
	while (n.size()&&x-n.front().Day>=n1)
	m.push_back(n.front()),n.pop_front();
	while (m.size()&&x-m.front().Day>=n2)
	o.push_back(m.front()),m.pop_front();
}
int Find(int x)
{
	while (n.size()) n.pop_front();
	while (o.size()) o.pop_front();
	while (m.size()) m.pop_front();
	int money=(tc-c2)*x;
	add(-200000,x);
	for (int i=1;i<=d;i++)
	{
		int rest=t[i];
		newch(i);
		while (rest&&o.size())
		{
			if (o.back().toys>rest)
			o.back().toys-=rest,money+=rest*c2,rest=0;
			else 
			rest-=o.back().toys,money+=c2*o.back().toys,o.pop_back();
		}
		while (rest&&m.size())
		{
			
			if (m.back().toys>rest)
			m.back().toys-=rest,money+=rest*c1,rest=0;
			else 
			rest-=m.back().toys,money+=c1*m.back().toys,m.pop_back();
		}
		if (rest) return inf;
		add(i,t[i]);
	}
	return money;
}
int three()
{
	 r=r+1;
	while (r-l>2) 
	{
		int x=(2*l+r)/3,y=(2*r+l)/3;
		int a=Find(x);
		if (a!=inf&&a<=Find(y)) r=y; 
		else l=x;
	}
	int ans=Find(l);
	for (int i=l+1;i<=r;i++)
		ans=min(ans,Find(i));
	return ans;
}
int main()
{
	scanf("%d%d%d%d%d%d",&d,&n1,&n2,&c1,&c2,&tc);
	if (n1>n2)
	swap(n1,n2),swap(c1,c2);
	if (c1<c2) c2=c1; 
	for (int i=1;i<=d;i++) scanf("%d",&t[i]),r+=t[i];
	printf("%d",three()); 
}


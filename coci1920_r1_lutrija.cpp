#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,x,y)for(i=x;i<=(y);i++)
ll c[6];
bool prime(ll p)
{
	if(p<2)return 0;
	int i;
	For(i,2,sqrt(p))
	if(!(p%i))return 0;
	return 1;
}
int main()
{
	ll a,b;
	cin>>a>>b;
	if(a==2&&b==2)cout<<-1,exit(0);
	if(llabs(a-b)==2)cout<<"2\n"<<a<<' '<<b,exit(0);
	int x,y,d=0,i;
	x=(prime(a-2)?1:(prime(a+2)?2:(a==2?3:0)));
	y=(prime(b-2)?1:(prime(b+2)?2:(b==2?3:0)));
	if(!x||!y)cout<<-1,exit(0);
	c[++d]=a;
	if(x==2)c[++d]=a+2;
	if(x!=3&&y!=3)c[++d]=2;
	if(y==2)c[++d]=b+2;
	c[++d]=b;
	cout<<d<<endl;
	For(i,1,d)cout<<c[i]<<' ';
	return 0;
}


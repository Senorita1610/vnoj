#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
const int N=1e6+5;
int n,m,k,l,r,t,ans,ll,rr,mm;
int sign(double x){return fabs(x)<=eps?0:(x>0?1:-1);}
struct point{
	double x,y;
	friend point operator -(point a,point b){return (point){a.x-b.x,a.y-b.y};}
	friend point operator +(point a,point b){return (point){a.x+b.x,a.y+b.y};}
	friend double operator *(point a,point b){return a.x*b.x+a.y*b.y;}
	friend double operator ^(point a,point b){return a.x*b.y-a.y*b.x;}
	friend point operator *(double k,point a){return (point){k*a.x,k*a.y};}
}a[N];
struct line{
	point x,y;
	double s;
	friend bool operator <(line x,line y)
	{
        return sign(x.s-y.s)==0?sign((x.y-x.x)^(y.y-x.x))>0:sign(x.s-y.s)<0;
	}
}b[N],q[N];
bool cmp2(line a,line b)
{
	return sign(a.s-b.s)==0;
}
point inter(line a,line b)
{
	point x1=a.x,x2=b.x,y1=a.y,y2=b.y;
    y1=y1-x1;y2=y2-x2;
    point u=x2-x1;
    point x=x2+((u^y1)/(y1^y2))*y2;
    return x;
}
bool pd(line i,line j,line k)
{
	point x=inter(i,j);
	return sign((k.y-k.x)^(x-k.x))<0;
}
bool work()
{
	t=0;
	sort(b+1,b+m+1);
    for(int i=1;i<=m;i++) 
	{
        if(sign(b[i].s-b[i-1].s)!=0) t++;
        b[t]=b[i];
    }
    l=1;r=0;
    q[++r]=b[1];q[++r]=b[2];
    for(int i=3;i<=t;i++)
	{
        while(l<r && pd(q[r-1],q[r],b[i]))r--;
        while(l<r && pd(q[l+1],q[l],b[i]))l++;
        q[++r]=b[i];
    }
    while(l<r && pd(q[r-1],q[r],q[l]))r--;
    while(l<r && pd(q[l+1],q[l],q[r]))l++;
    return r-l>1;
}
bool ok(int x)
{
	m=0;
	for(int i=2*n;i>=n+1;i--)
		b[++m].x=a[i],b[m].y=a[i-x];
	for(int i=1;i<=m;i++)b[i].s=atan2(b[i].y.y-b[i].x.y,b[i].y.x-b[i].x.x);
	return work();
}
int main()
{
	scanf("%d",&n);
	for(int j=1;j<=n;j++)
		scanf("%lf%lf",&a[j].x,&a[j].y),a[j+n]=a[j];
	ll=0,rr=(n-1)/2+1-1,ans=(n-1)/2+1-1;
	while(ll<=rr)
	{
		int mm=ll+rr>>1;
		if(ok(mm))ll=mm+1,ans=mm;
		else rr=mm-1;
	}
	printf("%d",ans);
}


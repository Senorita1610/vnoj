#include<cstdio>
long long n,t,x,ans,a[100001],b[200001];
int main()
{
    scanf("%lld%lld",&n,&x);
    a[0]=n;
    b[n]=1;
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&t);
        if (t>=x)a[i]=a[i-1]+1;
        else a[i]=a[i-1]-1;
    }
    t=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]>a[i-1])t-=b[a[i]];
        else t+=b[a[i-1]];
        b[a[i]]++;
        ans+=t;
    }
    printf("%lld",n*(n+1)/2-ans);
}


#include <stdio.h>
int read()
{
    int a=0,f=1;
    char b=getchar();
    while(b<'0'||b>'9') 
    {
		if(b=='-')
			f=-1;
		b=getchar();
	}
    while(b>='0'&&b<='9')
    {
        a=a*10+b-'0';
        b=getchar();
    }
    return a*f;
}
int main()
{
	long long x[1501],y[1501],s[1501][1501];
	int n=read(),ans=0;
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
		y[i]=read();
		for(int j=1;j<i;j++)
		{
			s[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(s[i][j]+s[i][k]==s[j][k]||s[i][j]+s[j][k]==s[i][k]||s[i][k]+s[j][k]==s[i][j])
					ans++;
	printf("%d",ans);
	return 0;
}


#include<cstdio>
#include<cstring>
const int maxn=1000010;
int n,kk,f[maxn],cnt;
char s[maxn];
int main()
{
	scanf("%d%d%s",&n,&kk,s);
	for(int i=1,j;i<n;++i)
	{
		j=f[i];
		while(j&&s[i]!=s[j]) j=f[j];
		if(s[i]==s[j]) f[i+1]=j+1;
	}
	for(int i=0;i<n;++i)
	{
		int t=(i+1)/(i+1-f[i+1]);
		if(t/kk+((i+1)%(i+1-f[i+1])==0)>t%kk) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}


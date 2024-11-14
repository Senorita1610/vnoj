#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
char s[100005];
int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		scanf("%s",s);
		int i,j;
		int pre=-1,ppre=-1;
		for(i=0;i<k;i++)
		{
			for(j=max(0,min(pre,ppre));j+1<n;j++)
			{
				if(s[j]=='4'&&s[j+1]=='7')
				{
					break;
				}
			}
			if(j+1==n||(ppre==j&&(k-i)%2==0)) break;
			if(j%2==0)
			{
				s[j+1]='4';
			}
			else s[j]='7';
			ppre=pre;
			pre=j;
		}
		puts(s);
	}
	return 0;
}


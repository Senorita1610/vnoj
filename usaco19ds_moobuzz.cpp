#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<stack>
#include<ctime>
#include<map>
#include<list>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int tmp1=n%8;
	int ans=n/8*15;
	int cnt=0;
	if(tmp1==0)
	{
		printf("%d\n",ans-1);
		return 0;
	}
	for(int i=1; i<=16; i++)
	{
		if(i%3!=0 && i%5!=0) cnt++;
		if(cnt==tmp1)
		{
			printf("%d\n",ans+i);
			return 0;
		}
	}
 	return 0;
}


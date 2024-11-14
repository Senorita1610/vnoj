#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int a[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	int sum=0,ans=1,num=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
			sum++;
		else if(a[i]==2)
			num++; 
		if(sum==num)
			ans++;
	}
	cout<<sum<<" "<<num<<endl;
	cout<<ans<<endl;
	int maxx=0;
	sum=0,num=0;
    for(int i=1;i<=n;i++)
    {
    	if(a[i]==1)
			sum++;
		else if(a[i]==2)
			num++;
    	int sheng=0;
    	if(a[i+1]!=a[i]&&((num>sum)||(sum>num)))
    	{
    		for(int j=i+1;j<=n;j++)
    		{
    			if(a[j]!=a[i])
    				sheng++;
    			else
    				break;
			}
			if(a[i]==1)
			{
				if(num+sheng>sum)
					maxx=max(maxx,sheng);
			}
			else 
			{
				if(sum+sheng>num)
					maxx=max(maxx,sheng);
			}
		}
	}
	cout<<maxx<<endl;
	return 0;
}


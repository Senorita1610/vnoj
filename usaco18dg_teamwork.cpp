#include <iostream>
using namespace std;
const int N=10005;
int n,k,s[N];
int f[N];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	f[1]=s[1];
	for(int i=2;i<=n;i++)
	{
		int mx=-1;
		for(int j=i;j>=max(i-k+1,1);j--)
		{
			mx=max(mx,s[j]);
			f[i]=max(f[i],f[j-1]+mx*(i-j+1));
		}
	}
	cout<<f[n];
    return 0;
}


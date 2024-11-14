#include <bits/stdc++.h>
using namespace std;
int a[2000000],b[2000000],d[2000000];
 
int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
	int n;cin>>n;
 
	int nn=n;
	n=(1<<n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<1000090;i++)
	{
		b[i]+=b[i-1];
	}
	for(int i=0;i<n;i++)
	{
	 d[i]=b[a[i]]-1;
	}
	int re=0;
	for(int i=0;i<n;i++)
	{
		re=0;
		int sum=1;
		for(int j=1 ;j<21;j++)
		{
		if ((sum)<=d[i]){
		re++;
		sum+=(1<<j);
		};	
		}
		cout<<nn-re<<" ";
	}
 
 return 0;
 
}


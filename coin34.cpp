#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;
long long f[35];
int d[35];
int n;
int main()
{
	int i,j,k;
	long long r;
	f[1]=0;
	f[1]=2; f[2]=3;f[3]=5;
	for(i=4;i<=34;i++)
		f[i]=f[i-1]+f[i-2]+f[i-3];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		cout<<"Case #"<<i<<": ";
		for(j=0;j<=34;j++)
			d[j]=0;
		cin>>r;
		k=34;
		while(f[1]<=r && k>0){
			for(j=k;j>=1;j--)
			{
				if (f[j]<=r)
				{
					r-=f[j];
					d[j]=1;
					k=j-1;
					break;
				}
			}
		}

		if(r>0) {
			cout<<"-1"<<endl;
			continue;
		}

		int t;
		do
		{
			t=1;
			for(k=3;k<=34;k++)

				if((d[k]==1) &&(d[k-1]==0)&&(d[k-2]==0)&&(d[k-3]==0))
				{
					d[k]=0;
					d[k-1]=d[k-2]=d[k-3]=1;
					t=0;
					break;
				}
			if(t==1) break;

		}
		while(true);
		int nMax=0;
		for(k=1;k<=34;k++)
			nMax+=d[k];
		cout<<nMax<<endl;

	}
}


#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
const ll maxn=100005;
const ll maxf=10e16;
ll L1,L2,L3,C1,C2,C3;
ll n,s,f,a[maxn];
ll F[maxn];
void Init()
{
	ios_base::sync_with_stdio(false);
	cin>>L1>>L2>>L3>>C1>>C2>>C3;
	cin>>n;
	cin>>s>>f;
	a[1]=0;
	for(int i=2;i<=n;i++) cin>>a[i];
}
void Solve()
{
	for(ll i=s+1;i<=f;i++)
	{
		F[i]=maxf;
		for(ll j=i-1;j>=s;j--)
		{
			if(a[i]-a[j]>L3) break;
			if(a[i]-a[j]>L2)
				F[i]=min(F[i],F[j]+C3);
			else
				if(a[i]-a[j]>L1)
					F[i]=min(F[i],F[j]+C2);
				else
					F[i]=min(F[i],F[j]+C1);
		}
	}
	cout<<F[f];
}
int main()
{
	Init();
	Solve();
}


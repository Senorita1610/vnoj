#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,n;
	cin>>a>>b>>n;
	ll x[3];
	x[0]=a;x[1]=b;x[2]=(a^b);
	cout<<x[n%3]<<endl;
	return 0;
}


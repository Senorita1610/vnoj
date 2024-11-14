#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	int x;
	cin>>x;
	ll brojac=0;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a<b)
			swap(a,b);
		if(a-b<=x)
			brojac+=a;
		else
		{
			int g;
			cin>>g;
			brojac+=g;
		}
	}
	cout<<brojac<<endl;
	return 0;
}


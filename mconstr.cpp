#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
int N,M;
string s[12],T;
main()
{
	while(cin>>N>>M,N)
	{
		for(int i=0;i<N;i++)cin>>s[i];
		T="";
		for(int i=0;i<M;i++)
		{
			string t;cin>>t;
			T+=t;
		}
		vector<bitset<4096> >dp(T.size()+1,1);
		vector<bitset<4096> >A(N);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<1<<N;j++)if(!(j>>i&1))A[i][j]=1;
		}
		int ans=0;
		for(int i=0;i<T.size();i++)
		{
			for(int j=0;j<N;j++)
			{
				if(s[j]!=T.substr(i,s[j].size()))continue;
				dp[i+s[j].size()]|=(dp[i]&A[j])<<(1<<j);
			}
			ans+=dp[i+1][(1<<N)-1];
		}
		cout<<ans<<endl;
	}
}


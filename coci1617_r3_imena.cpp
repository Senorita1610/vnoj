#include <bits/stdc++.h>
using namespace std;
bool punc(char c) 
{
	return (c=='.' || c=='?' || c=='!');
}
int main()
{
	int n;
	cin>>n;
	string s;
	int ans=0;
	while(n && cin>>s)
	{
		bool name=isupper(s[0]);
		for(int i=1;name && i<s.size() && !punc(s[i]);i++)
			name&='a'<=s[i]&&s[i]<='z';
		ans+=name;
		if(punc(s.back()))
		{
			cout<<ans<<endl;
			ans=0,n--;
		}
	}
	return 0;
}


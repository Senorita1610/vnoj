#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,a[M],t[M],l[M],r[M],ans;
vector<int>v[M];

struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void add(int x,int k){for (int i=x;i<=n;i+=lowbit(i))c[i]+=k;}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))res+=c[i];
		return res;
	}
	int query(int l,int r){return ask(r)-ask(l-1);}
}T;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),l[i]=t[a[i]]+1,t[a[i]]=i;
	for (int i=1;i<=n;i++)t[i]=0;
	for (int i=n;i>=1;i--)
		r[i]=t[a[i]]==0?n:t[a[i]]-1,t[a[i]]=i;
	for (int i=1;i<=n;i++)
		T.add(i,1),v[l[i]].pb(i);
	for (int i=n;i>=1;i--)
	{
		for (int j=0;j<v[i+1].size();j++)
		{
			int x=v[i+1][j];
			T.add(x,-1);
		}ans=ans+T.query(i,r[i]);
	}cout<<ans-n<<endl;
	return 0;
}


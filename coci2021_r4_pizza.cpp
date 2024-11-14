#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int f[103];
signed main()
{
    int n=read(),ans=0;
    for(int i=1; i<=n; i++) f[read()]=1;
    for(int t=read(),x; t--;)
    {
    	x=read();
    	bool g=1;
    	for(int i=1; i<=x; ++i) if(f[read()]==1) g=0;
    	ans+=g;
    }
    printf("%d\n",ans);
	return 0;
}


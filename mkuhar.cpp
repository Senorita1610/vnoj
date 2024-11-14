#include <bits/stdc++.h>
using namespace std;
int n,m,ans,x[101],y[101],sm[101],pm[101],sl[101],pl[101];	
inline int read(){
	int x=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
	return x;
}
inline bool check(int mid){
	int my=m;												
	for(int i=1;i<=n;i++){
		int t=2147483647;									
		int nd=mid*x[i]-y[i];								
		int k=nd/sl[i];										
		if(k*sl[i]<nd)k++;									
		while(k>=0){											
			int j=(max(0,nd-sl[i]*k))/sm[i];					
			if(j*sm[i]+k*sl[i]<nd)j++;							
			t=min(t,j*pm[i]+k*pl[i]);						
          		k--;
		}
		my-=t;
		if(my<0)return 0;									
	}
	return 1;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		x[i]=read(),y[i]=read(),
		sm[i]=read(),pm[i]=read(),
		sl[i]=read(),pl[i]=read();
	int l=0,r=100000,mid;									
	while(l<r){
		mid=(l+r)/2;
		if(check(mid))
        		l=mid+1,ans=mid;						
		else r=mid;											
	}
	printf("%d\n",ans);
	return 0;
}


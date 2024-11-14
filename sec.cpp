#include<iostream>
#include<cstdio>
using namespace std;
int n,m,t=1;
int b[500010],a[10010],d[500010];
int c[500010][2];
void tire(int x,int a[]){
   int u=1;
   for(int i=1;i<=x;i++){
   	if(c[u][a[i]]==0)
   		c[u][a[i]]=++t;
   	u=c[u][a[i]];
   	d[u]++;
   }
   b[u]++;
   return;
}
int tai(int x,int a[]){
   int u=1,ans=0,f=0;
   for(int i=1;i<=x;i++){
   	if(c[u][a[i]]!=0)
   		u=c[u][a[i]];
   	else{
   		f=1;
   		break;
   	}
   	if(b[u]!=0)
   		ans+=b[u];
   }
   if(f==0){
   	ans+=d[u];
   	if(b[u]!=0)
   		ans-=b[u];
   }
   return ans;
}
int main(){
   cin>>m>>n;
   int x;
   for(int i=1;i<=m;i++){
   	cin>>x;
   	for(int j=1;j<=x;j++)
   		cin>>a[j];
   	tire(x,a);
   }
   for(int i=1;i<=n;i++){
   	cin>>x;
   	for(int j=1;j<=x;j++)
   		cin>>a[j];
   	cout<<tai(x,a)<<endl;
   }
   return 0;
}


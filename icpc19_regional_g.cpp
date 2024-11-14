#include<bits/stdc++.h>
using namespace std;
int t,x,n,s,d,f,i,a[]={0,0,9,28,57,96,145,204,273,352,441};
vector<int>v;
int main(){
	for(scanf("%d",&t);t--;printf("%d\n",x<21?x-1:n),v.clear(),s=d=f=0){
		for(scanf("%d",&x),n=x;n;v.push_back(n%10),s+=n%10,n/=10,++d);
		if(s==v.back())
			for(n=1,s=0,i=v.size();i--;s+=v[i]=(v[i]+9)%10);
		for(n+=a[d-=!v.back()]+s-1,i=v.size();--i;
			n+=(f?!!v[i]:1<v[i]),f|=v[i]==1);
	}
	exit(0);
}


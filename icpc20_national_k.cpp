#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=1e6+10;
bool f(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4){
	double z1,z2,z3,z4;
	z1=((x2-x1)*(y4-y1)-(x4-x1)*(y2-y1));
	z2=((x4-x1)*(y3-y1)-(x3-x1)*(y4-y1));
	z3=((x4-x2)*(y3-y2)-(x3-x2)*(y4-y2));
	z4=((x3-x2)*(y1-y2)-(x1-x2)*(y3-y2));
	return (z1*z2>0)&&(z3*z4>0)||(z1*z2<=0)&&(z3*z4<=0);
}
bool se(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
	return (x2-x1)*(y3-y2)==(x3-x2)*(y2-y1);
}
int main(){
	int n;
	ll x[510],y[510];
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		ll ans=0;
		for(int i=0;i<n;i++) cin>>x[i]>>y[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if(se(x[i],y[i],x[j],y[j],x[k],y[k])) continue;
					for(int w=k+1;w<n;w++){
						if(se(x[i],y[i],x[j],y[j],x[w],y[w])||se(x[w],y[w],x[j],y[j],x[k],y[k])||se(x[i],y[i],x[w],y[w],x[k],y[k])) continue;
						if(f(x[i],y[i],x[j],y[j],x[k],y[k],x[w],y[w])) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


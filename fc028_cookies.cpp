#include<bits/stdc++.h>
using namespace std;
#define MAX 205
#define eps 1e-9
#define D(x) cout<<#x " = "<<(x)<<endl
double sqr(double x){
	return x*x;
}
typedef long long int ll;
struct info{
	double x,y;
}p[MAX];
int main(){
		int n=0,res=0;
		char str[100];
		while(gets(str)){
			if(strlen(str)==0) break;
			sscanf(str,"%lf %lf",&p[n].x,&p[n].y);n++;
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				info center;
				center.x=(p[i].x+p[j].x)/2.0;
				center.y=(p[i].y+p[j].y)/2.0;
				int ans=0;
				for(int k=0;k<n;k++){
					double dis=sqrt(sqr(center.x-p[k].x)+sqr(center.y-p[k].y));
					if(dis<=(2.5+eps)) ans++;
				}
				res=max(res,ans);
			}
		}
		cout<<res<<endl;
}


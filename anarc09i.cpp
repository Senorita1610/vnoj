#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
int n;
double a[105][105];
double ans[105];
void print(){
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n+1;k++){
			printf("%.2f ",a[j][k]);
		}
		puts("");
	}
	puts("");
}
void gauss(){
	int i,j,k;
	for(i=1,j=1;i<=n&&j<=n;){
		int max=i;
		for(k=i+1;k<=n;k++){
			if(fabs(a[k][j])>fabs(a[max][j])) max=k;
		}
		if(max!=i){
			for(k=j;k<=n+1;k++){
				swap(a[max][k],a[i][k]);
			}
		}
		if(a[i][j]==0){
			j++;
			continue;
		}
		for(k=i+1;k<=n;k++){
			if(a[k][j]==0) continue;
			double temp=a[k][j]/a[i][j];
			for(int l=j;l<=n+1;l++){
				a[k][l]=a[k][l]-temp*a[i][l];
			}
		}
		i++;
		j++;
	}
	for(int i=n;i>0;i--){
		ans[i]=a[i][n+1];
		for(int j=i+1;j<=n;j++){
			ans[i]=ans[i]-(a[i][j]*ans[j]);
		}
		ans[i]=ans[i]/a[i][i];
	}
}
int main(){
	int x,y,d;
	int cnt=0;
	while(scanf("%d %d %d",&y,&x,&d),y||x||d){
		if(cnt++) puts("");
		memset(a,0,sizeof a);
		double num[105];
		n=x*y;
		for(int i=1;i<=n;i++) scanf("%lf",&num[i]);
		int m[105]={0};
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				for(int k=1;k<=x;k++){
					for(int l=1;l<=y;l++){
						if(abs(i-k)+abs(j-l)<=d){
							a[(i-1)*y+(j-1)+1][(k-1)*y+(l-1)+1]=1;
							m[(i-1)*y+(j-1)+1]++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++) a[i][n+1]=num[i]*m[i];
		gauss();
		for(int i=1;i<=n;i++){
			printf("%8.2f",ans[i]);
			if(i%y==0) puts("");	
		} 
	}
	return 0;
}


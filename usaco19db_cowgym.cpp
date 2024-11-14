#include<bits/stdc++.h>
using namespace std;
int a[15][25],b[25][25],c[100010];
int main(){
	int n,k;
	int tot=0,cnt=0;
	cin>>k>>n;
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i!=j){
				for(int l=0;l<k;l++)
					for(int m=0;m<n-1;m++){
						if(a[l][m]==i){
							for(int o=m+1;o<n;o++)
								if(a[l][o]==j){
									b[i][j]++;
								}
						}
					}
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(b[i][j]==k){
				tot++;
			}
	cout<<tot;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
char a[55][55];
int main () {
	int r,c,zr,zc;
	cin>>r>>c>>zr>>zc;
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=r;i++){
		for(int m=1;m<=zr;m++){
			for(int j=1;j<=c;j++){
				for(int l=1;l<=zc;l++)
					putchar(a[i][j]);
			}	
			printf("\n"); 
		}
	}		
    return 0;
}


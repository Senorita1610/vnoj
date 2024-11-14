#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[110],numb[210][210];cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=2;
		numb[i][i]=numb[i+n][i+n]=a[i];
	}
	for(int l=2;l<=n;l++){
		for(int i=1;i<=(n<<1);i++){
			int j=i+l-1;
			if(j>(n<<1)){
				break;
			}
			numb[i][j]=max(numb[i][i]-numb[i+1][j],numb[j][j]-numb[i][j-1]);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(numb[i][i]-numb[i+1][i+n-1]>0){
			cnt++;
		}
	}
	cout<<cnt;
}


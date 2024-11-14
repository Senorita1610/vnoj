#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int b[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>b[i][j];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int temp=min({b[i-1][j],b[i+1][j],b[i][j-1],b[i][j+1]});
			cout<<temp<<' ';
			b[i-1][j]-=temp;
			b[i+1][j]-=temp;
			b[i][j-1]-=temp;
			b[i][j+1]-=temp;
		}
		cout<<'\n';
	}
}


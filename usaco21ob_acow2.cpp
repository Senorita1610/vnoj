#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;bool vis[101][101];string name[101];
map<string,int>id;signed main(){
	cin>>k>>n;for(int i=1;i<=n;i++)cin>>name[i],id[name[i]]=i;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)cin>>name[j];
		for(int j=1;j<=n;j++){
			int x=j+1;while(x<=n&&name[x]>name[x-1])x++;
			for(int y=x;y<=n;y++)vis[id[name[y]]][id[name[j]]]=1;
		}
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)cout<<"B";
			else if(!vis[i][j]&&!vis[j][i])cout<<"?";
			else cout<<vis[i][j];
		}cout<<endl;
	}return 0;
}


#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)(1e9+5))
#define MAX_X ((int)(1e6+2))
#define pi (2.0*acos(0))
#define M ((ll)(1e9+7))
#define NN ((ll)(305))
#define N ((int)(1e5+5))
#define eps (0)
#define log 20
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>o_set;
int x[]={-1,1,0,0};
int chk_x[]={-1,1,0,0};
int y[]={-1,-1,-1,-2};
int chk_y[]={0,0,-1,-1};
int dis[N];
string str[N];
int main(){
	int n,m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	memset(dis,-1,sizeof dis);
	dis[0]=0;
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int nod=q.front();
		q.pop();
		int row=nod/m,col=nod-row*m;
		for(int i=0;i<4;i++){
			int a=row+x[i],b=col+y[i],aa=row+chk_x[i],bb=col+chk_y[i];
			while(b<0) b+=m;
			while(bb<0) bb+=m;
			if(aa<0||a<0||a>=n||aa>=n) continue;
			if(str[aa][bb]=='M'||str[a][b]=='M') continue;
			int idx=a*m+b;
			if(dis[idx]==-1){
				dis[idx]=dis[nod]+1;
				q.push(idx);
			}
		}
	}
	int ans=MAX;
	for(int i=0;i<m;i++){
		if(dis[n*m-m+i]!=-1) ans=min(ans,dis[n*m-m+i]);
	}
	if(ans==MAX) ans=-2;
	cout<<ans+1<<endl;
	return 0;
}


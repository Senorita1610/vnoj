#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const char *dir[12]={"L","R","U","D","LL","LD","DD","RD","RR","RU","UU","UL"};
int dx[12]={-1,1,0,0,-2,-1,0,1,2,1,0,-1};
int dy[12]={0,0,1,-1,0,-1,-2,-1,0,1,2,1};
double sqr(double x){
	return x*x;
}
vector<pair<int,int>>p[2];
int main(){
	int cx=0,cy=0,u=0,flag=0,x;
	while(1){
		double sx=0,sy=0;
		if(flag){
			sort(p[u^1].begin(),p[u^1].end());
			p[u^1].erase(unique(p[u^1].begin(),p[u^1].end()),p[u^1].end());
			int cnt=0;
			for(auto pr : p[u^1]){
				cnt++;
				sx+=pr.first;
				sy+=pr.second;
			}
			sx/=cnt;
			sy/=cnt;
		}
		double dist=1e18;
		int id=0;
		for(int i=0;i<12;i++){
			int nx=cx+dx[i],ny=cy+dy[i];
			double dis=sqr(sx-nx)+sqr(sy-ny);
			if(dis<dist){
				dist=dis;
				id=i;
			}
		}
		if(rand()%5==0) id=rand()%8+4;
		if(flag&&x<=4){
			vector<int>can;
			for(int i=0;i<12;i++){
				int nx=cx+dx[i],ny=cy+dy[i];
				if(find(p[u^1].begin(),p[u^1].end(),make_pair(nx,ny))!=p[u^1].end()) can.push_back(i);
			}
			id=can[rand()%can.size()];
		}
		cx+=dx[id];
		cy+=dy[id];
		if(id<4){
			printf("%d %s\n",1,dir[id]);
		}
		else{
			printf("%d %s\n",2,dir[id]);
		}
		fflush(stdout);
		scanf("%d",&x);
		if(x==0) break;
		if(!flag){
			flag=1;
			for(int i=0;i*i<=x;i++){
				int mx=i,my=sqrt(x-i*i+0.5);
				if(mx*mx+my*my==x){
					p[u].push_back(make_pair(cx+mx,cy+my));
					if(mx){
						p[u].push_back(make_pair(cx-mx,cy+my));
					}
					if(my){
						p[u].push_back(make_pair(cx+mx,cy-my));
					}
					if(mx&&my){
						p[u].push_back(make_pair(cx-mx,cy-my));
					}
				}
			}
		}else{
			p[u].clear();
			for(auto pr : p[u^1]){
				for(int d=0;d<4;d++){
					int nx=pr.first+dx[d],ny=pr.second+dy[d];
					if(sqr(nx-cx)+sqr(ny-cy)==x) p[u].push_back(make_pair(nx,ny));
				}
			}
		}
		u^=1;
	}
}


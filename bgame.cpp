#include<cstdio>
#include<vector>
using namespace std;
const int N=305;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int Case,n,m,i,j,o,x,y,z,ca,cb,ax,ay,bx,by,nx,ny,A,F,B;
int d[N][N],d2[N][N],id[N][N],q[N*N],h,t;
char a[N][N];
vector<int>pool[N*N];
int cnt[N*N];
bool f[2][2][N*2][N*2];
inline void ext(int x,int y,int z){
  if(x<1||x>n||y<1||y>n)return;
  if(a[x][y]=='#')return;
  if(~d[x][y])return;
  d[x][y]=z;
  q[++t]=x<<9|y;
}
void bfs(int sx,int sy){
  int i,j;
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)d[i][j]=-1;
  h=1,t=0;
  ext(sx,sy,0);
  while(h<=t){
    int x=q[h++],y=x&511;x>>=9;
    for(i=0;i<4;i++)ext(x+dx[i],y+dy[i],d[x][y]+1);
  }
}
bool solve(){
  scanf("%d",&n);
  for(i=1;i<=n;i++)scanf("%s",a[i]+1);
  for(i=1;i<=n;i++)for(j=1;j<=n;j++){
    if(a[i][j]=='A')ax=i,ay=j;
    if(a[i][j]=='B')bx=i,by=j;
  }
  bfs(bx,by);
  m=d[ax][ay];
  if(m&1)return 1;
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)d2[i][j]=d[i][j];
  bfs(ax,ay);
  for(i=0;i<=m;i++)pool[i].clear(),cnt[i]=0;
  for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(d[i][j]>=0&&d[i][j]<=m){
    if(d[i][j]+d2[i][j]!=m){d[i][j]=-1;continue;}
    pool[d[i][j]].push_back(i<<9|j);
    id[i][j]=cnt[d[i][j]]++;
  }
  for(i=m,B=0;~i;i--,B^=1){
    ca=cnt[i];
    for(j=0;j<2;j++){
      o=m+j-i;
      if(o<0||o>m||i>o)continue;
      cb=cnt[o];
      for(x=0;x<ca;x++)for(y=0;y<cb;y++){
        if(i==o){
          f[B][j][x][y]=x==y?0:j^1;
          continue;
        }
        F=j;
        if(!j){
          ax=pool[i][x];
          ay=ax&511;ax>>=9;
          for(A=0;A<4;A++){
            nx=ax+dx[A],ny=ay+dy[A];
            if(nx<1||nx>n||ny<1||ny>n)continue;
            if(d[nx][ny]!=i+1)continue;
            if(f[B^1][1][id[nx][ny]][y]){F=1;break;}
          }
        }else{
          bx=pool[o][y];
          by=bx&511;bx>>=9;
          for(A=0;A<4;A++){
            nx=bx+dx[A],ny=by+dy[A];
            if(nx<1||nx>n||ny<1||ny>n)continue;
            if(d[nx][ny]!=o-1)continue;
            if(!f[B][0][x][id[nx][ny]]){F=0;break;}
          }
        }
        f[B][j][x][y]=F;
      }
    }
  }
  return f[B^1][0][0][id[bx][by]];
}
int main(){
  scanf("%d",&Case);
  while(Case--)puts(solve()?"A":"B");
}


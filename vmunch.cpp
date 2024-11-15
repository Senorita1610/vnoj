#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=9999999;
typedef pair<int,int>pos;
int R,C;
char Map[105][105];
int ans[105][105];
int bi,bj;
int ci,cj;
int X[4]={0,1,-1,0},Y[4]={1,0,0,-1};
int BFS(){
    queue<pos>que;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            ans[i][j]=inf;
    que.push(pos(bi,bj));
    ans[bi][bj]=0;
    while(que.size()){
        pos p=que.front();
        que.pop();
        if(p.first==ci&&p.second==cj)
            break;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                int xn=p.first+X[i];
                int yn=p.second+Y[i];
                if(xn>=0&&xn<R&&yn>=0&&yn<C&&ans[xn][yn]==inf&&Map[xn][yn]!='*'){
                    que.push(pos(xn,yn));
                    ans[xn][yn]=ans[p.first][p.second]+1;
                }
            }
    }
    return ans[ci][cj];
}
int main ()
{
    while(~scanf("%d%d",&R,&C)){
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++){
                cin>>Map[i][j];
                if(Map[i][j]=='B'){
                    bi=i;bj=j;
                }
                else if(Map[i][j]=='C'){
                    ci=i;cj=j;
                }
            }
        printf("%d\n",BFS());
    }
    return 0;
}


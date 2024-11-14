#include <cstdio>
#include <deque>
#define X first
#define Y second
 
using namespace std;
 
typedef pair<int,int> ii;
 
const int MAXR = 2003;
const int MAXS = 2003;
const int INF = 1000006;
const int DX[] = {0,0,-1,1};
const int DY[] = {-1,1,0,0};
const char DISCOUNT[] = "<>^v";
const char OPPOSITE[] = "><v^";
 
int r,s;
char mat[MAXR][MAXS];
int dist[MAXR][MAXS];
 
 
bool valid(ii p){
    return 0<=p.X && p.X<r && 0<=p.Y && p.Y<s;
}
 
void zobfs(ii start){
    deque<ii> to_visit;
    for(int i=0;i<MAXR;i++){
        for(int j=0;j<MAXS;j++) dist[i][j] = INF;
    }
 
    dist[start.X][start.Y] = 0;
    to_visit.push_back(start);
    while(!to_visit.empty()){
        ii curr = to_visit.front();
        to_visit.pop_front();
        if(mat[curr.X][curr.Y] == 'x') continue;
        for(int i=0;i<4;i++){
            ii nxt(curr.X + DX[i], curr.Y + DY[i]);
            if(valid(nxt)){
                int cost = 1;
                if(mat[curr.X][curr.Y] == 'o') cost = 0;
                if(DISCOUNT[i] == mat[curr.X][curr.Y]) cost = 0;
                if(dist[nxt.X][nxt.Y]>dist[curr.X][curr.Y]+cost){
                    dist[nxt.X][nxt.Y] = dist[curr.X][curr.Y] + cost;
                    if(cost == 1) to_visit.push_back(nxt);
                    else to_visit.push_front(nxt);
                }
            }
        }
    }
}
bool visited[MAXR][MAXS];
bool dfs(ii pos){
    visited[pos.X][pos.Y] = true;
    for(int i=0;i<4;i++){
        ii nxt(pos.X + DX[i], pos.Y + DY[i]);
        if(valid(nxt) && !visited[nxt.X][nxt.Y]){
            if(mat[nxt.X][nxt.Y] == 'o') return true;
            int cost = 1;
            if(mat[nxt.X][nxt.Y] == OPPOSITE[i]) cost = 0;
            if(dist[pos.X][pos.Y] == dist[nxt.X][nxt.Y]+cost){
                if(dfs(nxt)){
                    mat[nxt.X][nxt.Y] = OPPOSITE[i];
                    return true;
                }
            }
        }
    }
    return false;
}
 
int main(){
    scanf("%d%d", &r, &s);
    for(int i=0;i<r;i++){
        scanf("%s", mat[i]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<s;j++){
            if(mat[i][j] == 'o'){
                zobfs(ii(i, j));
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<s;j++){
            if(mat[i][j] == 'x'){
                printf("%d\n", dist[i][j]);
                dfs(ii(i, j));
            }
        }
    }
    for(int i=0;i<r;i++)
        puts(mat[i]);
}


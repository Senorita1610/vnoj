#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(), x.end()
#define MASK(i) (1 << i)
#define BIT(x, i) ((x >> i) & 1)

using namespace std;
#define NAME "a"
const int N = 305;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

bool maximize(int &x, int y){
    if(x < y){
        x = y;
        return true;
    } return false;
}
bool minimize(int &x, int y){
    if(x > y){
        x = y;
        return true;
    } return false;
}

struct State{
	int row, col, done;

	State(int _row = 0, int _col = 0, int _done = 0){
		row = _row; col = _col; done = _done;
	}
};

int dist[N][N][N];
int n, m, length;
char mat[N][N];
string target;

void init(){
    cin >> n >> m >> length;
    cin >> target;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mat[i][j];
}

bool canGo(int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int bfs(){
    memset(dist, -1, sizeof dist);
    queue<State> q;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dist[i][j][0] = 0;
            q.push(State(i, j, 0));
        }
    }

    while(!q.empty()) {
        int x = q.front().row;
        int y = q.front().col;
        int done = q.front().done;
        q.pop();
        if(done == length) return dist[x][y][done];

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(!canGo(xx, yy)) continue;

            int tmp = ((mat[xx][yy] == target[done]) ? done + 1 : done);
            if(dist[xx][yy][tmp] < 0){
                dist[xx][yy][tmp] = dist[x][y][done] + 1;
                q.push(State(xx, yy, tmp));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//    freopen(NAME".inp", "r", stdin);
//    freopen(NAME".out", "w", stdout);

    init();
    cout << bfs();
}


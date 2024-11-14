#include<stdio.h>
#include<queue>
using namespace std;
const int maxn = 100;
int r, c, n, cnt, vis[maxn + 5][maxn + 5], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
char mp[maxn + 5][maxn + 5];
bool isstone(int x, int y) {return x <= r && x && y <= c && y && mp[x][y] == 'x';}
struct node {int x, y;};
void bfs(int sx, int sy, int tag)
{
	queue<node> q;
	q.push({sx, sy});
	vis[sx][sy] = tag;
	while(!q.empty())
	{
		node t = q.front();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i], ny = t.y + dy[i];
			if(isstone(nx, ny) && !vis[nx][ny]) vis[nx][ny] = tag, q.push({nx, ny});
		}
	}
}
void calc()
{
	for(int i = 1; i <= r; i++) for(int j = 1; j <= c; j++) vis[i][j] = 0;
	cnt = 0;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			if(isstone(i, j) && !vis[i][j]) bfs(i, j, ++cnt);
}
void down(int tag)
{
	int ans = r + 1;
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			if(vis[i][j] == tag)
			{
				int dis = 0;
				while(dis <= r - i && (mp[i + dis][j] == '.' || vis[i + dis][j] == tag)) dis++;
				ans = ans < --dis? ans: dis;
			}
		}
	}
	for(int i = r; i > ans; i--)
	{
		for(int j = 1; j <= c; j++)
		{
			if(vis[i - ans][j] == tag) mp[i - ans][j] = '.', mp[i][j] = 'x';
		}
	}
}
void goal(int height, int side)
{
	int fst = -1;
	for(int i = side == 1? 1: c; i && i <= c; i += side)
	{
		if(mp[height][i] == 'x')
		{
			fst = i;
			break;
		}
	}
	if(!~fst) return;
	mp[height][fst] = '.';
	calc();
	int id = -1;
	for(int i = 0; i < 4; i++)
	{
		int nx = height + dx[i], ny = fst + dy[i];
		if(isstone(nx, ny))
		{
			if(~id && id != vis[nx][ny])
			{
				down(id), down(vis[nx][ny]);
				break;
			}
			id = vis[nx][ny];
		}
	}
}
int main()
{
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; i++) scanf("%s", mp[i] + 1);
	calc();
	scanf("%d", &n);
	for(int i = 1, height; i <= n; i++)
	{
		scanf("%d", &height);
		height = r - height + 1;
		goal(height, (i & 1)? 1: -1);
	}
	for(int i = 1; i <= r; i++) puts(mp[i] + 1);
	return 0;
}


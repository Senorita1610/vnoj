#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int fx[4] = {0,1,0,-1};
int fy[4] = {1,0,-1,0};
int pdx[8] = {-1,0,1,1, 1, 0,-1,-1};
int pdy[8] = { 1,1,1,0,-1,-1,-1, 0};
int N;
int Startx, Starty;
map<pair<int,int>, int> vist;
map<pair<int,int>, int> grass;
int x,y;
int maxx,maxy;
int minx = 1e6, miny = 1e6;
long long Answer;

bool DisNice(int x, int y) {
	for(int i = 0 ; i < 8 ; i++) {
		int gx = x+pdx[i];
		int gy = y+pdy[i];
		if(grass[{gx,gy}] != 0)
			return false;
	}
	return true;
}

void BFS()
{
	queue<pair<int,int> > Q;
	while(!Q.empty()) Q.pop();
	Q.push({Startx+1, Starty}); 
	while(!Q.empty()) {
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();
		
		if( vist[{X,Y}] != 0 || grass[{X,Y}] != 0)
			continue;
		vist[{X,Y}] = 1;
		for(int i = 0 ; i< 4 ; i++) {
			x = X+fx[i];
			y = Y+fy[i];
			if(grass[{x,y}] != 0) {
				Answer++;
			}
			if( vist[{x,y}] != 0 || grass[{x,y}] != 0 || DisNice(x,y)) {
				continue;
			} else {
				Q.push({x,y});
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 1 ; i<= N ; i++) {
		scanf("%d%d", &x, &y);
		grass[{x,y}] = 1;
		if(Startx < x) {
			Startx = x;
			Starty = y;
		}
	}
	BFS();
	printf("%d\n", Answer);
	return 0;
}


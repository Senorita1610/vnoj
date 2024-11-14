#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 2e2 + 5;
int n, x, y, z, l, r, cur, cure, cant;
int fa[maxn], dy[maxn], head[maxn], nex[maxn], to[maxn], val[maxn], dis[maxn];
bool al[maxn];
queue<int> q;
struct node{ 
	int u, v, w;
	bool ltmp[maxn], rtmp[maxn];
}ep[maxn];
void init(){ 
	for(int i = 0;i < maxn;i++){
		fa[i] = i;
	}
	return ;
}
int find(int x){ 
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){ 
	fa[find(x)] = find(y);
	return ;
}
void add(int u, int v, int w){
	nex[++cure] = head[u];
	to[cure] = v;
	val[cure] = w;
	head[u] = cure;
	return ;
}
void spfa(int s){ 
	memset(dis, 0x3f, sizeof(dis));
	memset(al, 0, sizeof(al));
	q.push(s);
	dis[s] = 0;
	al[s] = 1;
	while(!q.empty()){
		int fr = q.front();
		q.pop();
		al[fr] = 0;
		for(int i = head[fr];i;i = nex[i]){
			int t = to[i];
			int k = val[i];
			if(dis[fr] + k < dis[t]){
            	if(i == cant || i == cant + 1){ 
            		continue; 				
            	}
			    dis[t] = dis[fr] + k; 							
				if(al[t]){
					continue;
				}
				q.push(t);
				al[t] = 1;
			}
		}
	}
	return ;
}
int main(){
	init();
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d %d %d %d", &x, &z, &l, &r); 
		ep[x].u = 2 * x - 1;
		ep[x].v = 2 * x;
		ep[x].w = z;
		for(int j = 1;j <= l;j++){
			scanf("%d", &y);
			ep[x].ltmp[y] = 1; 
		}
		for(int j = 1;j <= r;j++){
			scanf("%d", &y);
			ep[x].rtmp[y] = 1;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j){
				continue;
			}
			if(ep[i].ltmp[j] && ep[j].ltmp[i]){
				merge(ep[i].u, ep[j].u);  	
			}
			if(ep[i].ltmp[j] && ep[j].rtmp[i]){
				merge(ep[i].u, ep[j].v);
			}
			if(ep[i].rtmp[j] && ep[j].ltmp[i]){
				merge(ep[i].v, ep[j].u);
			}
			if(ep[i].rtmp[j] && ep[j].rtmp[i]){
				merge(ep[i].v, ep[j].v);
			}
		}
	}
	for(int i = 1;i <= 2 * n;i++){
		if(fa[i] == i){
			dy[fa[i]] = ++cur;  
		}
	}
	for(int i = 1;i <= n;i++){
		ep[i].u = dy[find(ep[i].u)]; 
		ep[i].v = dy[find(ep[i].v)];
		add(ep[i].u, ep[i].v, ep[i].w); 
		add(ep[i].v, ep[i].u, ep[i].w);
	}
	int ans = 0x3f3f3f3f;
	for(int i = 1;i <= cure;i += 2){
		int j = (i + 1) / 2;
		cant = i; 
		spfa(ep[j].v); 
		ans = min(ans, ep[j].w + dis[ep[j].u]);  
	}
	printf("%d", ans); 
	return 0;
}


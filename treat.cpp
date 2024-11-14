#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n;
int to[N + 1];
int col[N + 1];
int dis[N + 1];
int dnf[N + 1];
int low[N + 1];
int nex[N + 1];
int res[N + 1];
bool in[N + 1];
int S[N + 1];
int top;
int tot;
int T;

void Tarjan(int x) {
	S[++top] = x;
	in[x] = 1;
	dnf[x] = low[x] = ++T;
	if(!dnf[to[x]]) {
		Tarjan(to[x]);
		low[x] = min(low[x], low[to[x]]);
	}
	else if(in[to[x]])
		low[x] = min(low[x], dnf[to[x]]);
	if(dnf[x] == low[x]) {
		int f = 0;
		tot++;
		while(f != x) {
			f = S[top--];
			dis[tot]++;
			in[f] = 0;
			col[f] = tot;
		}
	}
}
int get_res(int x) {
    if(nex[x] == x) return dis[x];
    if(res[x]) return res[x];
    return res[x] = dis[x] + get_res(nex[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &to[i]);
	for(int i = 1; i <= n; i++) if(!dnf[i]) Tarjan(i); 
	for(int i = 1; i <= n; i++) nex[col[i]] = col[i]; 
	for(int i = 1; i <= n; i++) if(col[i] != col[to[i]]) nex[col[i]] = col[to[i]];
	for(int i = 1; i <= n; i++) if(!res[col[i]]) res[col[i]] = get_res(col[i]);
	for(int i = 1; i <= n; i++) printf("%d\n", res[col[i]]);
	return 0;
}


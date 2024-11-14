#include<bits/stdc++.h>
using namespace std;
const int maxn = 513;
int n, a[maxn][maxn], ans[maxn][maxn], res[5][13], cnt1[5][13];
pair<int, int> tot[5];
int chosen[5], bst[5];
char s[maxn][maxn];
int count(int x, int y, int sz){
	int ret = 0;
	for(int i = 1; i <= sz; i++) for(int j = 1; j <= sz; j++)
		ret += a[x + i - 1][y + j - 1];
	return ret;
}
pair<int, int> getxy(int x, int y, int sz, int type){
	if(type == 2) x += sz;
	else if(type == 3) y += sz;
	else if(type == 4) x += sz, y += sz;
	return {x, y};
}
void color(int x, int y, int sz, int type, int col){
	auto tmp = getxy(x, y, sz, type);
	x = tmp.first, y = tmp.second;
	for(int i = 1; i <= sz; i++) for(int j = 1; j <= sz; j++)
		ans[x + i - 1][y + j - 1] = col;
}
int solve(int x, int y, int sz, int dep){
	if(sz == 1) return ans[x][y] = a[x][y], 0;
	int mid = sz >> 1, ret = 0;
	
	res[1][dep] = solve(x, y, mid, dep + 1), res[2][dep] = solve(x + mid, y, mid, dep + 1);
	res[3][dep] = solve(x, y + mid, mid, dep + 1), res[4][dep] = solve(x + mid, y + mid, mid, dep + 1);
	ret = sz * sz;
	auto tmp = getxy(x, y, mid, 1);
	cnt1[1][dep] = count(tmp.first, tmp.second, mid);
	tmp = getxy(x, y, mid, 2);
	cnt1[2][dep] = count(tmp.first, tmp.second, mid);
	tmp = getxy(x, y, mid, 3);
	cnt1[3][dep] = count(tmp.first, tmp.second, mid);
	tmp = getxy(x, y, mid, 4);
	cnt1[4][dep] = count(tmp.first, tmp.second, mid);
	for(int i = 1; i <= 4; i++) chosen[i] = i;
	
	do{
		int cur = mid * mid - cnt1[chosen[1]][dep] + cnt1[chosen[2]][dep] + res[chosen[3]][dep] + res[chosen[4]][dep];
		if(cur < ret){
			ret = cur;
			for(int i = 1; i <= 4; i++) bst[i] = chosen[i];
		}
	}while(next_permutation(chosen + 1, chosen + 5));
	
	color(x, y, mid, bst[1], 1);
	color(x, y, mid, bst[2], 0);
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= n; j++) a[i][j] = s[i][j] - '0';
	}
	printf("%d\n", solve(1, 1, n, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) printf("%d", ans[i][j]);
		puts("");
	}
	return 0;
}


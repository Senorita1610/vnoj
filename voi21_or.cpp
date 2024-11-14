#include<bits/stdc++.h>

using namespace std;
int fact[1000005], inv[1000005], cnt[1200005], n, k, l, r, f[1200005];
const int p =1e9+7, sign[] = {-1,1};
int nCr(int n, int r){
	if (r<0||r>n) return 0;
	return 1ll*fact[n]*inv[r]%p*inv[n-r]%p;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	cin >> n >> k >> l >> r;
	for (int i = 2; i <= n; i++) fact[i] = 1ll*fact[i-1]*i%p;
	for (int i = 2; i <= n; i++) inv[i] = 1ll*inv[p%i]*(p-p/i)%p;
	for (int i = 2; i <= n; i++) inv[i] = 1ll*inv[i-1]*inv[i]%p;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		cnt[a]++;
	}
	for (int i = 0; i < 20; i++){
		for (int mask = 0; mask < (1<<20); mask++) if (mask&(1<<i)){
			(cnt[mask] += cnt[mask^(1<<i)]);
		}
	}
	for (int i = 0; i < (1<<20); i++) f[i] = sign[__builtin_parity(i)]*nCr(cnt[i],k);
	for (int i = 0; i < 20; i++){
		for (int mask = 0; mask < (1<<20); mask++) if (mask&(1<<i)){
			(f[mask] += f[mask^(1<<i)]) %= p;
		}
	}
	int res = 0;
	for (int i = l; i <= r; i++) if (i%3==0) (res += sign[__builtin_parity(i)]*f[i]) %= p;
	cout << (res+p)%p;
	return 0;
}


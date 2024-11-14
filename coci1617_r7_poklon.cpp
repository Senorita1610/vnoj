#include <cstdio>
#include <cassert>
#include <cctype>
#include <algorithm>
#define let const auto
#define rep(name,beg,end) for(auto lim_##name = end,name = beg;name <= lim_##name;name++)
#define per(name,beg,end) for(auto lim_##name = end,name = beg;name >= lim_##name;name--)
#define repn(lim) for(auto REPN_lIM = lim,REPN = 1;REPN <= REPN_lIM;REPN++)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define trace() debug("line : %d, Function : %s\n",__LINE__,__FUNCTION__)
constexpr int maxn = 1e6 + 10;
using ll = long long;
using i128 = __int128_t;
int read(){
	int x = 0,f = 1; char c = std::getchar();
	while(!std::isdigit(c))f = c == '-' ? -1 : 1,c = std::getchar();
	while(std::isdigit(c))x = x * 10 + c - '0',c = std::getchar();
	return x * f;
}
template <typename T>
void wirte_bin(T x){
	char buf[233];
	int top = 0;
	do{
		buf[++top] = '0' + x % 2;
		x /= 2;
	}while(x);
	per(i,top,1)std::putchar(buf[i]);
}
struct Integer{
	ll v;
	int d;
	bool operator < (const Integer &rhs)const{
		if(std::abs(d - rhs.d) >= 64)return d < rhs.d;
		let v1 = i128(v) << (d - std::min(d,rhs.d));
		let v2 = i128(rhs.v) << (rhs.d - std::min(d,rhs.d));
		return v1 < v2;
	}	
}ans;
int n,ls[maxn],rs[maxn];
ll solve(const int x,const int dep = 0){
	if(x < 0){
		ans = std::max(ans,Integer{-x,dep});
		return -x;
	}
	ll res = 0;
	res += solve(ls[x],dep + 1);
	res += solve(rs[x],dep + 1);
	ans = std::max(ans,Integer{res,dep});
	return res;
}
int main(){
	n = read();
	rep(i,1,n)
		ls[i] = read(),rs[i] = read();
	solve(1);
	wirte_bin(ans.v);
	repn(ans.d)std::putchar('0');
	std::puts("");
	return 0;
}


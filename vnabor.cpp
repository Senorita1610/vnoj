#include <cstdio>
#include <algorithm>
#include <set>
typedef std::pair<long long,int> pli;
typedef std::pair<long long,long long> pll;
#define mk std::make_pair

const int N=1e5+5;
int n,C,fa[N],cnt[N];
pll a[N];
std::set<pli> s;

int find(int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	fa[find(x)]=find(y);
}
int main() {
	scanf("%d%d",&n,&C);
	for(int i=1;i<=n;++i) {
		int X,Y;
		scanf("%d%d",&X,&Y);
		a[i]=mk(X+Y,X-Y),fa[i]=i;
	}
	std::sort(a+1,a+n+1);
	s.insert(mk(-1LL<<60,0)),s.insert(mk(1LL<<60,0));
	s.insert(mk(a[1].second,1));
	for(int l=1,i=2;i<=n;++i) {
		while(a[i].first-a[l].first>C) s.erase(mk(a[l].second,l)),++l;
		std::set<pli>::iterator it=s.lower_bound(mk(a[i].second,0));
		if(it->first-a[i].second<=C) merge(i,it->second);
		--it;
		if(a[i].second-it->first<=C) merge(i,it->second);
		s.insert(mk(a[i].second,i));
	}
	int ans=0,mx=0;
	for(int i=1;i<=n;++i) ans+=(find(i)==i),mx=std::max(mx,++cnt[find(i)]);
	printf("%d %d\n",ans,mx);
	return 0;
}


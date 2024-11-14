#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
set<int>pos[N+5];
multiset<int>st;
int res,cnt;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    cnt=n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	pos[a[i]].insert(i);
    	st.insert(a[i]);
    }
    while (cnt>0) {
    	int x=*st.begin();
    	int p=*pos[x].begin();
    	pos[x].erase(pos[x].begin());
    	st.erase(st.lower_bound(x));
    	cnt--;
    	res++;
    	int l=p-1;
    	if (l>=1&&pos[a[l]].count(l)!=0) {
    		pos[a[l]].erase(pos[a[l]].find(l));
    		st.erase(st.lower_bound(a[l]));
    		cnt--;
    	}
    	int r=p+1;
    	if (r<=n&&pos[a[r]].count(r)!=0) {
    		pos[a[r]].erase(pos[a[r]].find(r));
    		st.erase(st.lower_bound(a[r]));
    		cnt--;
    	}
    }
    cout<<res;
}


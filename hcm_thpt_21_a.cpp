#include<bits/stdc++.h>
using namespace std;
int n,cur;
int cnt(int x) {
	int ans=0;
	while (x>0) {
		x/=10;
		ans++;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=4;;i++) {
		cur+=cnt(i);
		if (cur==n) {
			cout<<i;
			break;
		}
	}
}


#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long a[N+5],l[N+5],r[N+5];
priority_queue<long long,vector<long long>,greater<long long>>qmin;
priority_queue<long long>qmax;
long long res=LLONG_MIN;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=3*n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		l[i]=l[i-1]+a[i];
		qmin.push(a[i]);
	}
	for (int i=3*n;i>2*n;i--) {
		r[i]=r[i+1]+a[i];
		qmax.push(a[i]);
	}
	for (int i=n+1;i<=2*n;i++) {
		l[i]=l[i-1]+a[i];
		qmin.push(a[i]);
		l[i]-=qmin.top();
		qmin.pop();
	}
	for (int i=2*n;i>=n;i--) {
		r[i]=r[i+1]+a[i];
		qmax.push(a[i]);
		r[i]-=qmax.top();
		qmax.pop();
	}
	for (int i=n;i<=2*n;i++) {
		res=max(res,l[i]-r[i+1]);
	}
	cout<<res;
}


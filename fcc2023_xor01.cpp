#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,a[N+5],c[N+5];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	res+=c[a[i]]+c[(a[i]^1)];
    	c[a[i]]++;
    }	
    cout<<res;
}


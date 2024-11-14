#include<bits/stdc++.h>
using namespace std;
int t;
long long l,r;
long long calc(long long n) {
	if (n%4==0) return n;
	if (n%4==1) return 1;
	if (n%4==2) return n+1;
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>l>>r;
    	cout<<(calc(r)^calc(l-1))<<'\n';
    } 	
}


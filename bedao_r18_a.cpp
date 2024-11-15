#include<bits/stdc++.h>
using namespace std;
int t;
long long a,b;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>a>>b;
		if (a<0&&b<0) {
			a=-a;
			b=-b;
			long long g=__gcd(a,b);
			cout<<a/g<<' '<<b/g<<'\n';
		} else if (a<0) {
			if (-a==b) {
				cout<<0<<' '<<0<<'\n';
				continue;
			}
			else if (-a>b) {
				a=-a;
				b=-b;
			} 
			long long g=abs(__gcd(a,b));
			cout<<a/g<<' '<<b/g<<'\n';
		} else if (b<0) {
			if (a==-b) {
				cout<<0<<' '<<0<<'\n';
				continue;
			}
			else if (-b>a) {
				a=-a;
				b=-b;
			} 
			long long g=abs(__gcd(a,b));
			cout<<a/g<<' '<<b/g<<'\n';
		} else {
			long long g=__gcd(a,b);
			cout<<a/g<<' '<<b/g<<'\n';
		}
	}
}


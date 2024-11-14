#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
long long res,cnt[N+5];
vector<int>v;
void prep() {
	for (int i=1;i<=9;i++) {
		int temp=0;
		for (int j=1;j<=7;j++) {
			temp*=10,temp+=i;
			v.push_back(temp);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	prep();
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		cnt[a[i]]++;
	}
	for (auto x:v) {
		for (int i=1;i<=x/2;i++) {
			int j=x-i;
			if (i>N||j>N) continue;
			if (i==j) res+=cnt[i]*(cnt[i]-1)/2;
			else res+=cnt[i]*cnt[j];
		}
	}
	cout<<res;
}


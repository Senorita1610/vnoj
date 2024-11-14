#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,ans=0;
unordered_map <ll,ll> mp;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while (mp[n]==0){
        mp[n]=1;
        ans++;
        n++;
        if (n%10==0) n/=10;
	}
	cout<<ans;
}


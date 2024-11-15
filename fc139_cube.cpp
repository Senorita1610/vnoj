#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,ans=1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n;
	while (n-ans*(ans+1)/2>=0){
        n-=ans*(ans+1)/2;
        ans++;
	}
	cout<<ans-1;
}


#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,x,y;
string s;
void Check(ll x, ll y){
    while (x<y){
        if (s[x]!=s[y]){
            cout<<"NO"<<endl;
            return;
        }
        x++;
        y--;
    }
    cout<<"YES"<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x>>n>>s;
	while (n--){
        cin>>x>>y;
        Check(x-1,y-1);
	}
}


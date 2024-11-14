#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c,d;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b>>c>>d;
	if (a+d>b+c) cout<<"A wins";
	else if (a+d<b+c) cout<<"B wins";
	else if (a+d==b+c){
        if (b>d) cout<<"B wins";
        else if (b<d) cout<<"A wins";
        else cout<<"Extra time";
	}
}


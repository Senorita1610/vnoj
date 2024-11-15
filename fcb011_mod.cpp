#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string n;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while (n.size()<3) n='0'+n;
    while (n.size()>3) n.erase(0,1);
    cout<<n;
}


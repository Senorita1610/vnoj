#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,d=0,a=0;
string x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while (n--){
        cin>>x;
        if (x[0]=='-') a++;
        else if (x!="0") d++;
    }
    cout<<a<<" "<<d;
}


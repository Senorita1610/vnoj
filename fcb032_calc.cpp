#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>a>>b>>c){
        (max(a,max(b,c))*2==a+b+c) ? cout<<"yes"<<endl : cout<<"no"<<endl;
    }
}


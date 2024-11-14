#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a,b,c;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c;
    if (a%2==1){
        c--;
        a--;
    }
    if (b*2>a){
        c-=(b-a/2);
        b=a/2;
    }
    if (b*2<a){
        c-=(a-b*2);
        a=b*2;
    }
    cout<<(a+b-c*(c>0))/3;
}


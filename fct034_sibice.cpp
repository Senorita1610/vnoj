#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,w,h,a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>w>>h;
    while (n--){
        cin>>a;
        (a*a<=w*w+h*h) ? cout<<"DA"<<endl : cout<<"NE"<<endl;
    }
}


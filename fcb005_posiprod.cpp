#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n,a,x=0,y=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while (n--){
        cin>>a;
        if (a==0){
            cout<<-1;
            return 0;
        }
        (a>0) ? x++ : y++;
    }
    cout<<min(x,y);
}


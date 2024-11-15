#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,x,y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>a>>b>>x>>y;
        for (int c=0;c<=10000;c++) {
            if (((a+c)*x)%y!=0) continue;
            d=(a+c)*x/y-b;
            if (d>=0) {
                cout<<c+d<<'\n';
                break;
            }
        }
    }
}


#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    while (n--) {
        long long x;
        cin>>x;
        if (x%4==2||x==1) {
            cout<<"impossible"<<endl;
        } else if (x%2==1) {
            cout<<(x+1)/2<<' '<<(x-1)/2<<endl;
        } else {
            cout<<(x/2+2)/2<<' '<<(x/2-2)/2<<endl;
        }
    }
}


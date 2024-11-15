#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll a[20];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]>>a[10]>>a[11]>>a[12]){
        sort(a+1,a+13);
        if (a[12]==0) return 0;
        (a[1]==a[2] && a[2]==a[3] && a[3]==a[4] && a[5]==a[6] && a[6]==a[7] && a[7]==a[8] && a[9]==a[10] && a[10]==a[11] && a[11]==a[12]) ? cout<<"yes"<<endl : cout<<"no"<<endl;
    }
}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 10002
int n,m;
int r[MAX], a[MAX], F[MAX];
string brige;

int Cal(int r)
{
    int i=0; 
    int res = 1;
    while(i+r<=m)
    {
        res++;
        i+=r;
        while(brige[i-1]=='1') i--;
    }
    return res;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>r[i];
    cin>>brige;
    for(int i=1;i<=n;i++) a[i] = Cal(r[i]);
    sort(a+1, a+n+1);
    F[1] = a[1];
    F[2] = a[2];
    for(int i=3;i<=n;i++)
    {
        F[i] = min(F[i-1] + a[1] + a[i], F[i-2] + a[1] + 2*a[2] + a[i]);
    }
    cout<<F[n];

}


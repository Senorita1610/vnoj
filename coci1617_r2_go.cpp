#include <bits/stdc++.h>
#define intt long long
#define forn(i,n) for(i=0;i<n;i++)
#define rforn(i,n) for(i=n-1;i>=0;i--)
#define FAST_READ ios_base::sync_with_stdio(false)
#define r0 return 0
using namespace std;
intt n,m,k,evo=0,maxi=-1,i,cnt;
int main()
{
    string s,maxevo;
    cin>>n;
    while(n){
        cnt=0;
        cin>>s;
        cin>>m>>k;
        while(k>=m){
            k-=m;k+=2;
            cnt++;
        }
        if(cnt>maxi){maxevo=s;maxi=cnt;}
        evo+=cnt;
        n--;
    }
    cout<<evo<<endl<<maxevo<<endl;
    r0;
}


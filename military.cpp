#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define task "c"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
typedef  pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll N = 1e5;
const ll mod =1e9+9;
const ll base = 311;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void operator -= (ii& A,ii B)
{
    A.fi-=B.fi;
    A.se-=B.se;
}
bool clr(ii a,ii b,ii c)
{
    c-=b;
    b-=a;
    return b.fi*c.se>c.fi*b.se;
}
ii a[4005];
bool cmp(ii a,ii b)
{
    if(a.fi!=b.fi)return a.fi<b.fi;
    else return a.se<b.se;
}
bool check[4005];
void nhap()
{
    int n,x,y;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].fi>> a[i].se ;
    }
    sort(a+1,a+1+n);
    ll ans=0;
    ll hull[4005];
    while(n>2)
    {
        int k=1;
        for(int i = 1 ; i<=n ; i++)
        {
            check[i]=false;
            while(k>2&&clr(a[hull[k-2]],a[hull[k-1]],a[i]))k--;
            hull[k]=i;
            k++;
        }
        int t=k+1;
        for(int i = n ; i>=1; i--)
        {
            while(k>t&&clr(a[hull[k-2]],a[hull[k-1]],a[i]))k--;
            hull[k]=i;
            k++;
        }
        for(int i = 1 ; i <k; i++)
        {
            check[hull[i]]=true;
        }
        int m=1;
        for(int i= 1 ; i <= n ; i++)
        {
            if(!check[i])
            {
                a[m]=a[i];
                m++;
            }

        }
        n=m-1;
        ans++;
    }
    cout << ans << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}


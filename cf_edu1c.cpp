#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define BS binary_search
#define SIZE 2000100
#define mod 1000000007LL
#define bpc __builtin_popcount

using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num=num*10+c;
        c=getchar();
    }
    return num*sign;
}

pair<long double,int> D[100043];

int main()
{
    long double a360=atan(1)*8;
    long double a180=atan(1)*4;

    int n=getnum();

    for(int i=1;i<=n;i++)
    {
        int a=getnum(),b=getnum();
        long double x=a,y=b;
        if(x==0)
        {
            if(y>0)D[i].ff=atan(1)*2;
            else D[i].ff=atan(1)*6;
        }
        else
        {
            if(x>0&&y>=0)D[i].ff=atan(y/x);
            else if(x>0&&y<0)D[i].ff=a360+atan(y/x);
            else if(x<0&&y>=0)D[i].ff=a180+atan(y/x);
            else D[i].ff=a180+atan(y/x);
        }
        D[i].ss=i;
    }
    sort(D+1,D+n+1);

    D[1+n]=D[1];
    D[1+n].ff+=a360;

    long double mn=a360+a180;
    int x;

    for(int i=1;i<=n;i++)
    {
        if(D[i+1].ff-D[i].ff<mn)mn=D[i+1].ff-D[i].ff,x=i;
    }
    cout<<D[x].ss<<' '<<D[x+1].ss;
}


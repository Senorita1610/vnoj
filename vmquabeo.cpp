#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int N=(int)1e6+7;
const int MOD=(int)1e9+7;
const ll INF=(ll)1e18+7;
deque<ll> ma,mi;
ll mapos,mipos,res,n,l,d;
vector<ll> a;
int main()
{
    cin>>n>>l>>d;

    a.resize(n+1);
    a[0]=0;

    for (int i=1;i<=n;i++)
        cin>>a[i];

    ma.push_back(1);
    mi.push_back(1);
    mapos=mipos=1;
    res=0;

    for (ll i=2;i<=n;i++)
    {
        while (mi.size() && a[mi.back()]>a[i]) mi.pop_back();
        mi.push_back(i);
        while (a[i]-a[mi.front()]>d) mipos=mi.front()+1,mi.pop_front();

        while (ma.size() && a[ma.back()]<a[i]) ma.pop_back();
        ma.push_back(i);
        while (a[ma.front()]-a[i]>d) mapos=ma.front()+1,ma.pop_front();

        ll pos=i-max(mipos,mapos)+1;
        if (pos<l) continue;
        res+=pos-l;
    }

    cout<<res;
}


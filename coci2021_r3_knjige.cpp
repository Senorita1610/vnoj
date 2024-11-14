#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[101];
string op[100001];
vector<int>l,r;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=n;i;--i)l.push_back(a[i]);
    sort(a+1,a+n+1);
    for(int i=1,t;i<=n;++i)
    {
        t=0;
        while(l.back()!=a[i])
        {
            op[++cnt]="UZMI L L\n";
            op[++cnt]="STAVI L D\n";
            r.push_back(l.back());
            l.pop_back();
            ++t;
        }
        op[++cnt]="UZMI D L\n";
        l.pop_back();
        while(t--)
        {
            op[++cnt]="UZMI L D\n";
            op[++cnt]="STAVI L L\n";
            l.push_back(r.back());
            r.pop_back();
        }
        op[++cnt]="STAVI D D\n";
        r.push_back(a[i]);
    }
    while(r.size())
    {
        op[++cnt]="UZMI L D\n";
        op[++cnt]="STAVI L L\n";
        l.push_back(r.back());
        r.pop_back();
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;++i)cout<<op[i];
    return 0;
}


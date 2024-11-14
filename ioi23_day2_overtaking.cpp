#include<bits/stdc++.h>
using namespace std;
 
long long br=0, x, n, m;
pair<long long, long long> buses[500005];
long long tabl[1005][1005];
long long ans[1005][1005];
vector<int> s;
 
void init(int L, int N, std::vector<long long> T, std::vector<int> W, int X, int M, std::vector<int> S)
{
    x=X;
    s=S;
    m=M;
    for(int i=0; i<N; i++)
    {
        if(W[i]<=X) continue;
        br++;
        buses[br-1]={T[i], W[i]};
    }
    sort(buses, buses+br);
    N=br;
    n=N;
    for(int i=0; i<N; i++) tabl[0][i]=buses[i].first;
    for(int i=1; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            buses[j].first+=buses[j].second*(S[i]-S[i-1]);
            if(j) buses[j].first=max(buses[j].first, buses[j-1].first);
            tabl[i][j]=buses[j].first;
        }
        sort(buses, buses+br);
    }
    for(int j=0; j<N; j++) ans[M-1][j]=tabl[M-1][j];
    for(int i=M-2; i>=0; i--)
    {
        ans[i][0]=tabl[i][0]+x*(S[M-1]-S[i]);
        for(int j=1; j<N; j++)
        {
            if(tabl[i][j]==tabl[i][j-1]) {ans[i][j]=ans[i][j-1]; continue;}
            long long ep=tabl[i][j]+x*(S[M-1]-s[i]);
            if(ep>=tabl[M-1][j-1]) ans[i][j]=ep;
            else
            {
                int le=i, ri=M-1;
                while(ri-le>1)
                {
                    int mid=(le+ri)/2;
                    ep=tabl[i][j]+x*(S[mid]-s[i]);
                    if(ep>tabl[mid][j-1]) le=mid;
                    else ri=mid;
                }
                ans[i][j]=ans[ri][j-1];
            }
        }
    }
}
 
long long arrival_time(long long Y)
{
    ///cout<<Y<<" ";
    if(Y<=tabl[0][0]) return Y+x*(s[m-1]-s[0]);
    int le=0, ri=n;
    while(ri-le>1)
    {
        int mid=(le+ri)/2;
        if(tabl[0][mid]<Y) le=mid;
        else ri=mid;
    }
    int j=ri;
    long long ep=Y+x*(s[m-1]-s[0]);
    if(ep>=tabl[m-1][ri-1]) return ep;
    le=0;
    ri=m-1;
    while(ri-le>1)
    {
        int mid=(le+ri)/2;
        ep=Y+x*(s[mid]-s[0]);
        if(ep>tabl[mid][j-1]) le=mid;
        else ri=mid;
    }
    ///ans[i][j]=ans[ri][j-1];
    ///cout<<ri<<" "<<j-1<<endl;
    return ans[ri][j-1];
}


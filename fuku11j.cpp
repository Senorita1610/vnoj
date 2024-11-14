#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1e8+7;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

vector<vector<int>> path;
vector<P> va;
int t[100][2];
typedef vector<int> V1;
typedef vector<vector<int>> V2;
typedef vector<vector<vector<int>>> V3;
const int dis_n=20;
int dis[dis_n][dis_n][dis_n][dis_n];

void memset_dis(){
    int a,b,c,d;
    for(a=0;a<dis_n;a++){
        for(b=0;b<dis_n;b++){
            for(c=0;c<dis_n;c++){
                for(d=0;d<dis_n;d++){
                    dis[a][b][c][d]=INF;
                }
            }
        }
    }
}

void check(int ta,int tb,vector<int>& v1){
    if(ta<=tb){
        v1.push_back(tb-ta);
        check(ta,tb-1,v1);
        v1.pop_back();
        check(ta,tb-1,v1);
        return;
    }
    if(v1.empty())return;
    int n=v1.size();
    int i,j,k,l;
    int a,b,c,d;
    int s;
    vector<vector<int>> dis_temp(n,vector<int>(n,INF));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a=ta+v1[i],b=ta+v1[j];
            dis_temp[i][j]=path[a][b];
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                dis_temp[i][j]=min(dis_temp[i][j],dis_temp[i][k]+dis_temp[k][j]);
            }
        }
    }
    s=0;
    for(i=0;i<n;i++){
        s+=t[ta+v1[i]][0];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                for(l=0;l<n;l++){
                    a=v1[i],b=v1[j],c=v1[k],d=v1[l];
                    dis[a][b][c][d]=min(dis[a][b][c][d],s+dis_temp[i][k]+dis_temp[j][l]);
                }
            }
        }
    }
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c,d;
    int x,y;
    while(cin>>n>>m){
        if(!n)break;
        path.assign(n,vector<int>(n,INF));
        va.assign(1e3+7,P(n+10,-1));
        vector<tuple<int,int,int>> vt1;
        vector<int> v1(n);
        V2 dp(n+10,V1(n+10,INF));
        vt1.push_back(make_tuple(0,0,0));
        vt1.push_back(make_tuple(1e3,0,n-1));
        for(i=1;i<n-1;i++){
            cin>>a>>b;
            vt1.push_back(make_tuple(b,a,i));
        }
        sort(vt1.begin(),vt1.end());
        for(i=0;i<n;i++){
            tie(a,b,c)=vt1[i];
            v1[c]=i;
            va[a].first=min(va[a].first,i);
            va[a].second=max(va[a].second,i);
            t[i][0]=b,t[i][1]=a;
        }
        t[n-1][1]=1e3;
        for(i=0;i<m;i++){
            cin>>a>>b>>c;
            a--,b--;
            a=v1[a],b=v1[b];
            path[a][b]=min(path[a][b],c);
        }
        for(i=0;i<n;i++){
            path[i][i]=0;
        }
        dp[0][0]=0;
        for(i=0;i<=1e3;i++){
            if(va[i].first>n)continue;
            memset_dis();
            v1.clear();
            x=va[i].first,y=va[i].second;
            check(x,y,v1);
            m=y-x+1;
            vector<vector<int>> dp_temp(m+10,vector<int>(m+10,INF));
            for(j=0;j<m;j++){
                for(k=0;k<m;k++){
                    for(a=0;a<x;a++){
                        if(path[a][x+j]==INF)continue;
                        for(b=0;b<x;b++){
                            if(path[x+k][b]==INF)continue;
                            dp_temp[j][k]=min(dp_temp[j][k],dp[a][b]+path[a][x+j]+path[x+k][b]);
                        }
                    }
                }
            }
            for(j=0;j<m;j++){
                for(k=0;k<m;k++){
                    for(a=0;a<m;a++){
                        for(b=0;b<m;b++){
                            dp[x+a][x+b]=min(dp[x+a][x+b],dp_temp[j][k]+dis[j][b][a][k]);
                        }
                    }
                }
            }
            for(j=0;j<=y;j++){
                for(a=0;a<x;a++){
                    for(b=0;b<m;b++){
                        for(c=0;c<m;c++){
                            dp[j][x+c]=min(dp[j][x+c],dp[j][a]+path[x+b][a]+dis[b][c][b][b]);
                            dp[x+c][j]=min(dp[x+c][j],dp[a][j]+path[a][x+b]+dis[b][b][c][b]);
                        }
                    }
                }
            }
        }
        int s=dp[n-1][n-1];
        if(s>=INF)s=-1;
        cout<<s<<endl;
    }
}


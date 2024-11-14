#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 1010;
string arr[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++)cin>>arr[i];
    string col = "TB";
    int now = 0;
    queue<pii> q[2];
    if(col[now] != arr[0][0])now^=1;
    q[now].push({0,0});
    arr[0][0] = '*';
    int ans = 0;
    pii dir[] = {{0,1},{0,-1},{1,0},{-1,0}};
    while(!q[0].empty()||!q[1].empty()){
        ans++;
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<m;j++)cout<<arr[i][j];cout<<endl;
        // }
        // cout<<ans<<' '<<q[0].size()<<' '<<q[1].size()<<endl;
 
        while(!q[now].empty()){
            auto pos = q[now].front();
            q[now].pop();
            for(auto &i:dir){
                pii nxt = {pos.fs+i.fs,pos.sc+i.sc};
                if(nxt.fs<0||nxt.fs>=n||nxt.sc<0||nxt.sc>=m||arr[nxt.fs][nxt.sc] == '*')continue;
                q[(col[now] == arr[nxt.fs][nxt.sc]?now:now^1)].push(nxt);
                arr[nxt.fs][nxt.sc] = '*';
            }
        }
        now^=1;
    }
    cout<<ans;
}


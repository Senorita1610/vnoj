#include <bits/stdc++.h>
using namespace std;
 
const int N=5e3+10;
string s,t;
int cnt[2][5];
int n;
 
bool ok(){
    bool kq=1;
    for(int i=0;i<3;++i)kq&=(cnt[0][i]>=0);
    kq&=(cnt[0][0]<=cnt[1][1]+cnt[1][2]);
    kq&=(cnt[0][1]<=cnt[1][0]+cnt[1][2]);
    kq&=(cnt[0][2]<=cnt[1][0]+cnt[1][1]);
 
    return kq;
}
 
signed main(){
    cin>>n>>s>>t;
    //cout<<s<<' '<<t<<endl;
    for(int i=0;i<n;++i){
        cnt[0][s[i]-'a']++;
        cnt[1][t[i]-'a']++;
    }
 
    string ans="";
    for(int i=0;i<n;++i){
        cnt[1][t[i]-'a']--;
        for(int j=0;j<3;++j){
            if(j!=t[i]-'a'){
                cnt[0][j]--;
                if(ok()){
                    ans+=(char)('a'+j);
                    break;
                }
                ++cnt[0][j];
            }
        }
    }
    cout<<ans<<endl;
}


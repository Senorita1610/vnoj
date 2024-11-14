#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define endl '\n'
using namespace std;
 
 
const int months[13]={-1,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<array<int,3>> v,dates;
 
void print(array<int,3> x){
    if(x[2]<10) cout<<0<<x[2];
    else cout<<x[2];
    cout<<'.';
    if(x[1]<10) cout<<0<<x[1];
    else cout<<x[1];
    cout<<'.';
    if(x[0]<1000) cout<<0<<x[0];
    else cout<<x[0];
    cout<<'.'<<endl;
}
 
bool check(int yy, int mm, int dd){
    
    if(mm>12 || mm==0) return false;
    if((yy%4==0) && mm==2 && dd==29) return true;
    if(0<dd && dd<=months[mm]) return true;
    return false;
}
 
void solve(){
    string s; cin>>s;
    array<int,3> a;
    a[0]=(s[6]-'0')*1000+(s[7]-'0')*100+(s[8]-'0')*10+s[9]-'0';
    a[1]=(s[3]-'0')*10+s[4]-'0';
    a[2]=(s[0]-'0')*10+s[1]-'0';
    
    auto it=upper_bound(dates.begin(),dates.end(),a);
    auto x=*it;
    print(x);
}
 
int32_t main(){
    cin.tie(0)->sync_with_stdio(false);
    
    for(int i=0;i<=10000;i++){
        
        int d=i%100; int m=i-d;
        d=(d%10)*10 + d/10;
        m/=100;
        m=(m%10)*10 + m/10;
        
        if(check(i,m,d)){
            dates.pb({i,m,d});
        }
    }
    dates.pb({110101, 10, 10});
    
    int t; cin>>t;
    while(t--) solve();
 
    return 0;
}


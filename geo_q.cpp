#include<bits/stdc++.h>
using namespace std;
long double xp,yp,xa,ya,xb,yb,a,b,c;
bool mid(long long xa,long long ya,long long xb,long long yb,long long xc,long long yc) {
    int cnt=0;
    if ((xa<=xb&&xb<=xc)||(xa>=xb&&xb>=xc)) cnt++;
    if ((ya>=yb&&yb>=yc)||(ya<=yb&&yb<=yc)) cnt++;
    return (cnt==2);
}
int main() {
    cin>>xp>>yp>>xa>>ya>>xb>>yb;
    a=yb-ya;
    b=xa-xb;
    c=xb*ya-xa*yb;
    if (a*xp+b*yp+c!=0) {
        cout<<"NO";
        return 0;
    }
    if (mid(xa,ya,xp,yp,xb,yb)) cout<<"YES";
    else cout<<"NO";
}


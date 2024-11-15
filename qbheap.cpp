#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll v,d=0,a[15551];
char k;
priority_queue <ll> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>k){
        if (k=='+' && pq.size()<15000){
            cin>>v;
            pq.push(v);
        }
        else if (k=='-' && !pq.empty()){
            ll o=pq.top();
            while (pq.top()==o && !pq.empty()) pq.pop();
        }
    }
    while (!pq.empty()){
        if (pq.top()!=a[d]){
            d++;
            a[d]=pq.top();
        }
        pq.pop();
    }
    cout<<d<<endl;
    for (ll i=1;i<=d;i++) cout<<a[i]<<endl;
}


#include <bits/stdc++.h>
#define ll long long int

using namespace std;

char k;
stack <char> st1,st2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>k){
        if (k!='<' && k!='>' && k!='-') st1.push(k);
        else if (k=='-' && !st1.empty()) st1.pop();
        else if (k=='<' && !st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        else if (k=='>' && !st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    while (!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    while (!st2.empty()){
        cout<<st2.top();
        st2.pop();
    }
}


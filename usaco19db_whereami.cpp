#include<bits/stdc++.h>
using namespace std;
string s;
bool b=false;  
int n;
void Compare(int k){
    for(int i=0;i<=n-k;i++)
    {
        string ss;
        ss=s.substr(i,k);  
        if(s.find(ss,i+1)!= string::npos)
        {
            return;  
        }
        if(i==n-k)  
        {
            cout<<k<<endl;
            b=true;
            return;
        }
    }
}
int main(){
    cin>>n;
    cin>>s;
    int k=1;
    while(!b) 
    {
        k++;
        Compare(k);
    }
    return 0;
}


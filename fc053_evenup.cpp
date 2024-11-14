#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,x;
stack<int>st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>x;
		if (!st.empty()) {
			if ((st.top()+x)%2==0) st.pop();
			else st.push(x);
		} else st.push(x);
	}
	cout<<st.size();
}


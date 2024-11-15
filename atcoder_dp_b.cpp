#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int N,K;
	cin>>N>>K;
	vector<int>heights(N);
	vector<int>costs(N);
	for(int i=0;i<N;i++){
		cin>>heights[i];
	}
	for(int i=0;i<K;i++){
		costs[i]=abs(heights[i]-heights[0]);
	}
	for(int i=K;i<N;i++){
		int minCost=abs(heights[i]-heights[i-K])+costs[i-K];
		for(int j=i-K;j<i;j++){
			int contendCost=abs(heights[i]-heights[j])+costs[j];
			if(contendCost<minCost){
				minCost=contendCost;
			}
		}
		costs[i]=minCost;
	}
	cout<<costs[N-1]<<"\n";
}


#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int n, arr[50000], m , X, Y;

struct node{
	int prefixMaxSum, suffixMaxSum, maxsum, sum;
	
	void assignLeaf(int value) {
		prefixMaxSum = suffixMaxSum = maxsum = sum = value;
	}
	
	void merge(node& left, node& right) {
		sum = left.sum + right.sum;
		prefixMaxSum = max(left.prefixMaxSum, left.sum + right.prefixMaxSum);
		suffixMaxSum = max(right.suffixMaxSum, right.sum + left.suffixMaxSum);
		maxsum = max(prefixMaxSum, max(suffixMaxSum, max(left.maxsum, max(right.maxsum, left.suffixMaxSum + right.prefixMaxSum))));
	}
};
node tree[150001];

void init(int i, int l, int r){
	if(l == r){
		tree[i].assignLeaf(arr[l]);
	}
	else{
		init(2*i, l, (l+r)/2);
		init((2*i) + 1, ((l+r)/2) + 1, r);
		node left = tree[2*i], right = tree[(2*i)+1];
		tree[i].merge(left, right);	
	}
	return;
}
node query(int i, int l, int r, int lo, int hi){
	if(l == lo and r == hi)				
		return tree[i];
	int mid = (l+r)/2;
	if(lo > mid)					
		return query((2*i)+1, mid+1, r, lo, hi);
	if(hi <= mid)				
		return query(2*i, l, mid, lo, hi);
	node left = query(2*i, l, mid, lo, mid);	
	node right = query((2*i)+1, mid+1, r, mid+1, hi);
	node result;
	result.merge(left, right);		
	return result;
}
	
int main(){
	sd(n);
	for(int i = 0; i < n; i++) sd(arr[i]);
	
	init(1, 0, n-1);
	
	sd(m);
	while(m--){
		sd2(X,Y);
		printf("%d\n",query(1,0,n-1,X-1,Y-1).maxsum);
	}
	
	return 0;
}


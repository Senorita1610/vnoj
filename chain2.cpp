#include<iostream>
using namespace std;
const int ALSZ = 26;
int ans = 0;
struct trie_node{
	trie_node *child_node[ALSZ];
	int isEnd;
};
trie_node *GetNode(void){
	trie_node *p_node = new trie_node;
	p_node->isEnd = 0;
	for (int i = 0; i<ALSZ; i++){
		p_node->child_node[i] = 0;
	}
	return p_node;
}
void insert(trie_node *root, string key){
	trie_node *crawl_node = root;
	int dem = 1;
	for (int i = 0; i<key.length(); i++){
		int idx = key[i] - 'a';
		if (!crawl_node->child_node[idx]){
			crawl_node->child_node[idx] = GetNode();
		}
		crawl_node = crawl_node->child_node[idx];
		dem += crawl_node->isEnd;
	}
	crawl_node -> isEnd ++;
	ans = max(ans, dem);
}
int main(){
	trie_node *root = GetNode();
	int n;
	cin>>n;
	for (int i = 0; i<n; i++){
		string s;
		cin>>s;
		insert(root, s);
	}
	cout<<ans;
}


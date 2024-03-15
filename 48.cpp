#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

struct Node {
	Node *l,*r;
	int data;
};

void dfs(Node *node){
	if(node->l!=NULL) dfs(node->l);
	if(node->r!=NULL) dfs(node->r);
	cout<<node->data<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n;
	Node *root=new Node,*cur=root;
	cin>>m;
	root->data=m;
	for(int i=2;i<=n;i++){
		cur=root;
		cin>>m;
		while(m!=-1){
			if(m<cur->data){
				if(cur->l!=NULL){
					cur=cur->l;
				}else{
					cur->l=new Node;
					cur->l->data=m;
					m=-1;
				}
			}else{
				if(cur->r!=NULL){
					cur=cur->r;
				}else{
					cur->r=new Node;
					cur->r->data=m;
					m=-1;
				}
			}
		}
	}
	dfs(root);
}

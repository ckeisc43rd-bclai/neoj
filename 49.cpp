#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


struct node{
	int has=1;
	node *in;
	node(){
		in=NULL;
	}
	//int id;
};


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t,n,m,p,q,z,u;
	node *boxes[100007];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		for(int j=0;j<=n+1;j++){
			boxes[j]=new node;
		}
		for(int j=1;j<=m;j++){
			cin>>p>>q;
			boxes[q]->in=boxes[p];
			boxes[p]->has+=boxes[q]->has;
			node *cur=boxes[p]->in;
			while(cur!=NULL){
				cur->has+=boxes[q]->has;
				cur=cur->in;
			}
		}
		cin>>z;
		while(z--){
			cin>>u;
			cout<<boxes[u]->has<<endl;
		}
	}
}

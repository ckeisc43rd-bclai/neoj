#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;


struct node{
    int id;
    node *next,*pre;
    node(){
        next=NULL;
        pre=NULL;
    }
};


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,N,m,process,num;
    cin>>n;
    N=n;
    node *players[100007];
    for(int i=0;i<=n+1;i++){
        players[i]=new node();
        players[i]->id=i;
    }
    players[0]->next=players[1];
    for(int i=1;i<=n;i++){
        players[i]->pre=players[i-1];
        players[i]->next=players[i+1];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>process>>num;
        if(process==0){
            players[num]->pre->next=players[num]->next;
            players[num]->next->pre=players[num]->pre;
        }else{
            if(!players[num]->pre->id) continue;
            int pp,p,n;
            pp=players[num]->pre->pre->id;
            p=players[num]->pre->id;
            n=players[num]->next->id;
            players[pp]->next=players[num];
            players[num]->pre=players[pp];
            players[num]->next=players[p];
            players[p]->pre=players[num];
            players[p]->next=players[n];
            players[n]->pre=players[p];
        }
    }
    int i=players[0]->next->id;
    queue<int> ans;
    while(players[i]->id!=n+1){
        ans.push(players[i]->id);
        i=players[i]->next->id;
    }
    while(ans.size()!=1){
        cout<<ans.front()<<" ";
        ans.pop();
    }
    cout<<ans.front()<<endl;
}